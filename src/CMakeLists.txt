add_executable(game_engine main.cpp engine.cpp game.cpp input.cpp renderer.cpp platform.cpp logger.cpp)
target_link_libraries(game_engine PRIVATE SDL3::SDL3)
if(WIN32)
    add_custom_command(
        TARGET game_engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:SDL3::SDL3>
                $<TARGET_FILE_DIR:game_engine>
    )
endif()

add_custom_command(
    TARGET game_engine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:game_engine>/assets"
    VERBATIM
)

target_include_directories(game_engine PRIVATE ${CMAKE_SOURCE_DIR}/include)