#pragma once
#include "../Components/IComponentFactory.h"
#include "../Vector2D.h"

class RenderCreator final :IComponentFactory
{
   void InitializeComponent(std::shared_ptr<IComponent> component) override;

public:
    RenderCreator() = default;
    std::shared_ptr<IComponent> CreateComponent(std::shared_ptr<Entity> owner, 
        Vector2D imageSize, std::string imageName);
};

