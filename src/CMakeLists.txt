add_executable(game_engine main.cpp)
target_link_libraries(game_engine PRIVATE SDL3::SDL3)
if(WIN32)
    add_custom_command(
        TARGET game_engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:SDL3::SDL3>
                $<TARGET_FILE_DIR:game_engine>
    )
endif()
target_include_directories(game_engine PRIVATE ${CMAKE_SOURCE_DIR}/include)