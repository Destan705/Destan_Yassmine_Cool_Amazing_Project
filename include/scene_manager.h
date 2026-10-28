#pragma once 
#include "event_dispatcher.h"
#include "scene.h"
#include <memory>

class SceneManager{

public:
explicit SceneManager(EventDispatcher& dispatcher);
void setActiveScene(std::unique_ptr<Scene> scene);
Scene& activeScene();
void update(float dt);

private:
std::unique_ptr<Scene> currentScene;
EventDispatcher& eventDispatcher;
};