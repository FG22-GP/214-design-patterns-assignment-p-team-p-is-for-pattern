#pragma once
#include "IComponent.h"
#include "..\Vector2D.h"

class Render final : public IComponent, std::enable_shared_from_this<Render> {

    Vector2D spriteSize;
    std::string imageName;

public:
    Render(const std::shared_ptr<Entity>& Owner, Vector2D size, std::string imgName);

    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
