add_executable(engine_tests test_renderer.cpp test_platform.cpp ../src/renderer.cpp ../src/platform.cpp test_input.cpp test_engine.cpp test_logger.cpp ../src/input.cpp ../src/engine.cpp ../src/placeholder.cpp ../src/logger.cpp)
target_link_libraries(engine_tests PRIVATE GTest::gtest_main SDL3::SDL3)
target_include_directories(engine_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Windows needs SDL3.dll next to the test executable, just like the game engine.

if(WIN32)
    add_custom_command(
        TARGET engine_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
                $<TARGET_FILE:SDL3::SDL3>
                $<TARGET_FILE_DIR:engine_tests>
    )
endif()
add_custom_command(
    TARGET engine_tests POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${PROJECT_SOURCE_DIR}/assets"
            "$<TARGET_FILE_DIR:engine_tests>/assets"
    VERBATIM
)

include(GoogleTest)
gtest_discover_tests(engine_tests DISCOVERY_MODE PRE_TEST WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}" PROPERTIES TIMEOUT 30)