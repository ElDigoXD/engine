

function(copy_runtime_dlls TARGET)
    add_custom_command(TARGET ${TARGET} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Engine::Core>
            $<TARGET_FILE_DIR:${TARGET}>

        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Engine::Math>
            $<TARGET_FILE_DIR:${TARGET}>
    )
endfunction()