#pragma once

#include <concepts>

constexpr std::size_t KiB(std::size_t x)
{
    return x * 1024ull;
}

constexpr std::size_t MiB(std::size_t x)
{
    return KiB(x) * 1024ull;
}

template<typename T>
concept c_allocator_type = requires(std::size_t size, std::size_t alignment)
{
    { T::name }        -> std::convertible_to<const char*>;

    { T::allocate(size, alignment) } -> std::same_as<void*>;
    { T::deallocate(std::declval<void*>(), size, alignment) };
};

namespace core
{
    //Move to another folder
    // struct DefaultAllocator
    // {
    //     static constexpr const char* name = R"(Default allocator)";
    //
    //     static void* allocate(std::size_t size);
    //     static void  deallocate(void* ptr);
    // };

    class Allocator
    {
        static constexpr std::size_t PAGE_SIZE = MiB(1);

        struct Block
        {
            static constexpr std::size_t FREE_BIT = 1;

            std::size_t size_and_flags;

            std::size_t size() const;

            bool is_free() const;

            void set_free(bool value);

            void set_size(std::size_t size);

            Block* prev;
            Block* next;
        };

        struct AllocationHeader
        {
            Block* block;
        };

        struct Page
        {
            void* memory;
            Page* next;
        };

        Page* Pages_ = nullptr;

    public:
        Allocator() = default;

        Allocator(const Allocator&) = delete;
        Allocator& operator=(const Allocator&) = delete;

        ~Allocator();

        void* allocate(std::size_t size,
                       std::size_t alignment = alignof(std::max_align_t));

        void deallocate(void* ptr); // NOLINT(*-convert-member-functions-to-static)

        void release();

    private:
        Block* first_block(const Page* p); // NOLINT(*-convert-member-functions-to-static)

        static std::uintptr_t align_up(
            const std::uintptr_t address,
            const std::size_t alignment);

        void* try_allocate(Block* b,
            const std::size_t size,
            const std::size_t alignment); // NOLINT(*-convert-member-functions-to-static)

        void split(Block* block, std::size_t size);

        void merge(Block* a, const Block* b);

        Block* block_from_ptr(void* ptr);

        Page* create_page(
            std::size_t size,
            std::size_t alignment);
    };


}
