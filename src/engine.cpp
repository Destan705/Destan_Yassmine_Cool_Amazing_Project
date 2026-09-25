#include "../include/placeholder.h" 
#include <iostream>
#include <chrono>

using namespace std;


void engine() {

    bool running = initializePlatform();

    if (!running) {
        cout << "Error occured while initializing engine";
    }


    float delta_time = 0.0f;
    auto prev_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();


    while (running) {
        auto current_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
        //  Process Input
        running = processPlatformEvents();
        
        if (!running) {break;}

        //  Update Engine State
        delta_time = (current_time - prev_time)/1000.0f;
        updateEngineState(delta_time);

        //  Render Engine Frame
        renderPlatform();
        prev_time = current_time;
    }

    // Shutdown system
    shutdownPlatform();

}