#pragma once
#include "IComponent.h"
#include "..\Vector2D.h"

class Render final : public IComponent, std::enable_shared_from_this<Render> {

    Vector2D spriteSize;

public:
    explicit Render(std::string name ,const std::shared_ptr<Entity>& Owner, Vector2D size, std::string imgName);

    std::string imageName;
    void Start() override;
    void Execute() override;
    void Stop() override;
    std::string GetName() override;
    void InitializeComponent() override;
};
