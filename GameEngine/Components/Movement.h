#pragma once
#include "IComponent.h"
#include "../Vector2D.h"
#include "../Engine/Entity.h"

class Movement final : public IComponent, std::enable_shared_from_this<Movement> {
public:
    Vector2D Velocity;

    Vector2D& ConsumeVelocity();
    
    explicit Movement(std::string name, const std::shared_ptr<Entity>&Owner);
    void Translate(Vector2D Translation);

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
