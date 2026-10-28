#pragma once

#include "rendertypes.h"

class Renderer;

bool initializePlatform();
void shutdownPlatform();

Renderer& getRenderer();
textureHandle getDefaultTexture();