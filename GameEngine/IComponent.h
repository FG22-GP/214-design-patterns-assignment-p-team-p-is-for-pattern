#pragma once
#include "string"


class IComponent {
protected:
    IComponent();
    std::string componentName;

public:
    virtual ~IComponent();

    virtual void Start();
    virtual void Execute();
    virtual void Stop();
    std::string GetName();
};

class EntityComponent : public IComponent {
public:
    EntityComponent() = default;
    void Start() override;
    void Execute() override;
    void Stop() override;
};
