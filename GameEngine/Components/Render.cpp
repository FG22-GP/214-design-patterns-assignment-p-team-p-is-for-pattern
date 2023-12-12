#include "Render.h"

#include "..\Engine\Entity.h"
#include "..\TextureManager.h"

Render::Render(std::string name ,const std::shared_ptr<Entity>& Owner,Vector2D size,std::string imgName)
: IComponent(Owner) {
    componentName = name;
    imageName = imgName;
    spriteSize = size;
    TheTextureManager::Instance()->LoadImage("img/SDLSprites/" + imageName + ".png", imageName);
}

void Render::Start() {
}

void Render::Execute() {
    TheTextureManager::Instance()->Draw(imageName, owner->position, spriteSize);
}

void Render::Stop() {
}

std::string Render::GetName() {
    return IComponent::GetName();
}

void Render::InitializeComponent() {
}
