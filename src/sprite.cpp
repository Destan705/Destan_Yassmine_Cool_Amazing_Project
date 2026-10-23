#include "transform.h"
#include "sprite.h"
#include "entity.h"

Sprite::Sprite(textureHandle handle){
    currentTexture = handle;
}

void Sprite::render(Renderer& renderer){

   Entity* owner= getOwner();
   if(owner==nullptr){
    return;
   }
   Transform* transform = owner->getComponent<Transform>();
    if(transform==nullptr){
        return;
    }

    Bounds bounds{transform->x, transform->y, transform->width, transform->height};

}