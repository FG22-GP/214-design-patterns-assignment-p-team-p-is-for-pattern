#include "RenderCreator.h"
#include <memory>

#include "Entity.h"
#include "..\Components\Render.h"

void RenderCreator::InitializeComponent(std::shared_ptr<IComponent> component)
{
}

std::shared_ptr<IComponent> RenderCreator::CreateComponent(std::shared_ptr<Entity> owner ,
    Vector2D imageSize, std::string imageName)
{
    auto entityComponent = std::make_shared<Render>(owner, imageSize, imageName);
    InitializeComponent(entityComponent);
    return entityComponent;
}
