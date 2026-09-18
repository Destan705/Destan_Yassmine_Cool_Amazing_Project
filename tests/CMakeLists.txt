add_executable(engine_tests test_sanity.cpp)
target_link_libraries(engine_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(engine_tests)