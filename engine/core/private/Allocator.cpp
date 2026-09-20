#include "Core/Allocator.h"

#include <cassert>
#include <new>
#include <utility>
#include <cstddef>

std::size_t core::Allocator::Block::size() const
{
    return size_and_flags & ~FREE_BIT;
}

bool core::Allocator::Block::is_free() const
{
    return (size_and_flags & FREE_BIT) != 0;
}

void core::Allocator::Block::set_free(const bool value)
{
    if (value)
        size_and_flags |= FREE_BIT;
    else
        size_and_flags &= ~FREE_BIT;
}

void core::Allocator::Block::set_size(std::size_t size)
{
    size_and_flags =
            (size & ~FREE_BIT) |
            (size_and_flags & FREE_BIT);
}

core::Allocator::~Allocator()
{
    release();
}

void* core::Allocator::allocate(std::size_t size, std::size_t alignment)
{
    assert(alignment != 0);
    assert((alignment & (alignment - 1)) == 0);

    if (size == 0)
        return nullptr;

    // Primero intentamos reutilizar memoria.
    for (const Page* p = Pages_; p; p = p->next)
    {
        Block* b = first_block(p);

        while (b)
        {
            if (b->is_free())
            {
                //Puede que el tamaño no sea suficiente y retorne null.
                if (void* result = try_allocate(b, size, alignment))
                    return result;
            }

            b = b->next;
        }
    }

    // No hemos encontrado espacio.
    // Creamos una página nueva.
    const Page* p = create_page(size, alignment);

    if (!p)
        throw std::bad_alloc{};

    Block* b = first_block(p);

    void* result = try_allocate(b, size, alignment);

    if (!result)
        throw std::bad_alloc{};

    return result;
}

void core::Allocator::deallocate(void* ptr)
{
    if (!ptr)
        return;

    const AllocationHeader* header =
        reinterpret_cast<AllocationHeader*>(
            static_cast<std::byte*>(ptr)
            - sizeof(AllocationHeader));

    Block* block = header->block;

    block->set_free(true);

    // Primero intentamos fusionar con el siguiente.
    if (block->next &&
        block->next->is_free())
    {
        merge(block, block->next);
    }

    // Después con el anterior.
    if (block->prev &&
        block->prev->is_free())
    {
        merge(block->prev, block);
    }
}

void core::Allocator::release()
{
    const Page* p = Pages_;

    while (p)
    {
        const Page* next = p->next;

        ::operator delete(p->memory);
        delete p;

        p = next;
    }

    Pages_ = nullptr;
}

core::Allocator::Block* core::Allocator::first_block(const Page* p)
{
    return static_cast<Block*>(p->memory);
}

std::uintptr_t core::Allocator::align_up(
    const std::uintptr_t address,
    const std::size_t alignment)
{
    const auto mask = static_cast<std::uintptr_t>(alignment - 1);

    return (address + mask) & ~mask;
}

void* core::Allocator::try_allocate(
    Block* block,
    const std::size_t size,
    const std::size_t alignment)
{
    if (!block->is_free())
        return nullptr;

    const std::uintptr_t block_start =
        reinterpret_cast<std::uintptr_t>(block);

    const std::uintptr_t raw_data_start = block_start + sizeof(Block);

    const auto data_start =
            align_up(
                raw_data_start +
                sizeof(AllocationHeader),
                alignment);

    const auto header_start =
            data_start - sizeof(AllocationHeader);

    // [Block start][ padding ][ AllocationHeader ][ user data ]
    const auto padding =
            data_start - (block_start + sizeof(Block));

    const auto required =
        (data_start + size) - block_start;

    if (required > block->size())
        return nullptr;

    // Dividimos el bloque si queda suficiente espacio.
    split(block, required);

    // Ahora el bloque está ocupado.
    block->set_free(false);

    auto* header =
        reinterpret_cast<AllocationHeader*>(
            header_start);

    header->block = block;

    return reinterpret_cast<void*>(data_start);
}

void core::Allocator::split(Block* block, const std::size_t size)
{
    constexpr std::size_t MIN_REMAINDER =
            sizeof(Block) + alignof(std::max_align_t);

    if (block->size() <
        size + MIN_REMAINDER)
    {
        return;
    }

    const auto address =
        reinterpret_cast<std::uintptr_t>(block);

    Block* new_block =
        reinterpret_cast<Block*>(
            address + size);

    new_block->size_and_flags =
        block->size() - size;

    new_block->set_free(true);

    new_block->prev = block;
    new_block->next = block->next;

    if (new_block->next)
        new_block->next->prev = new_block;

    block->next = new_block;

    block->set_size(size);
}

void core::Allocator::merge(Block* a, const Block* b)
{
    // a y b deben ser bloques adyacentes.
    a->set_size(
        a->size() + b->size());

    a->next = b->next;

    if (a->next)
        a->next->prev = a;
}

core::Allocator::Block* core::Allocator::block_from_ptr(void* ptr)
{
    // El Block está antes de la memoria del usuario.
    //
    // OJO:
    // esto presupone que el padding de alignment
    // no separa arbitrariamente el header del pointer.
    //
    // Para un allocator de producción conviene guardar
    // el offset/header de forma explícita.

    const std::uintptr_t address =
            reinterpret_cast<std::uintptr_t>(ptr);

    return reinterpret_cast<Block*>(address - sizeof(Block));
}

core::Allocator::Page* core::Allocator::create_page(
    const std::size_t size,
    const std::size_t alignment)
{
    void* memory = ::operator new(PAGE_SIZE + sizeof(Page));

    auto* page = static_cast<Page*>(memory);

    page->memory = static_cast<std::byte*>(memory) + sizeof(Page);
    page->next = Pages_;

    Pages_ = page;

    auto* block = static_cast<Block*>(memory);

    block->size_and_flags = PAGE_SIZE;

    block->set_free(true);

    block->prev = nullptr;
    block->next = nullptr;

    return page;
}
