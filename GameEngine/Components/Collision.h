#pragma once
#include "IComponent.h"

class Collision final : public IComponent, std::enable_shared_from_this<Collision> {
public:
    explicit Collision(std::string name, const std::shared_ptr<Entity>& Owner);

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
