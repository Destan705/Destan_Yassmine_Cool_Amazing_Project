add_executable(engine_tests test_renderer.cpp test_platform.cpp ../src/renderer.cpp ../src/platform.cpp)
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

include(GoogleTest)
gtest_discover_tests(engine_tests DISCOVERY_MODE PRE_TEST PROPERTIES TIMEOUT 30)