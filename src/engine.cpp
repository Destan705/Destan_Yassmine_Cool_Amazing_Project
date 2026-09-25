#include "../include/placeholder.h" 
#include <iostream>

using namespace std;


void engine() {

    cout << "Starting up engine";

    bool running = true; 
    while (running) {
        //  Process Input
        if (eventDetected()) {
            cout << "Process event";
            cout << "Convert event into usable input for engine";

            
            if (checkCloseWindow()) {
                break;
            }
        }

        //  Update Engine State
        updateEngineState();

        //  Render Engine Frame
        renderEngine();

    }

    // Shutdown system
    cout << "Shutting down engine";

}