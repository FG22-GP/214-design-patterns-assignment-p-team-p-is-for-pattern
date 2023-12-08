#pragma once
#include "string"


class IComponent {
protected:
    IComponent();
    std::string componentName;

public:
    virtual ~IComponent();

    virtual void Start() = 0;
    virtual void Execute() = 0;
    virtual void Stop() = 0;
    virtual std::string GetName();
    virtual void InitializeComponent() = 0;
};

// Example Component :D
class EntityComponent final : public IComponent {
public:
    explicit EntityComponent(std::string name);
    void Start() override;
    void Execute() override;
    void Stop() override;
    void InitializeComponent() override;
    std::string GetName() override;
};
