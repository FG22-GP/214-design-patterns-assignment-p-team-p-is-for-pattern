#pragma once
#include "IComponent.h"
#include "../Vector2D.h"

class Entity;

class Movement final : public IComponent, std::enable_shared_from_this<Movement> {
public:
    Movement(const std::shared_ptr<Entity>& Owner);
    void Translate(Vector2D Translation) const;

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
