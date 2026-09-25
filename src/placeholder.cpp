#include "../include/placeholder.h"
#include <iostream>

using namespace std;


bool checkCloseWindow() {
    cout << "Close Window";
    return true;
}

bool processPlatformEvents() {
    cout << "Process event";
    cout << "Convert event into usable input for engine";
    return true;
}

void updateEngineState(float delta_time) {
    cout << delta_time;
    cout << "Update Engine State";
}

void renderPlatform() {
    cout << "Rendering Platform";
}

bool initializePlatform() {
    cout << "Initializing Platform";
    return true;
}

void shutdownPlatform() {
    cout << "Shutting Down Platform";
}