add_executable(game_engine main.cpp)
target_link_libraries(game_engine PRIVATE SDL3::SDL3)
target_include_directories(game_engine PRIVATE ${CMAKE_SOURCE_DIR}/include)