#pragma once
#include "IComponent.h"

/**
 * \brief Example Component :D
 */
class EntityComponent final : public IComponent {
public:
    explicit EntityComponent(std::string name, std::shared_ptr<Entity>& Owner);
    void Start() override;
    void Execute() override;
    void Stop() override;
    void InitializeComponent() override;
    std::string GetName() override;
};
