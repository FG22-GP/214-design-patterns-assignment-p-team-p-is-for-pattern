#pragma once
#include "IComponent.h"

class Render final : public IComponent, std::enable_shared_from_this<Render> {
public:
    Render(const std::shared_ptr<Entity>& Owner);

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
