#pragma once

class IComponent {
protected:
    IComponent();

public:
    virtual ~IComponent();

    virtual void Start();
    virtual void Execute();
    virtual void Stop();
};

class EntityComponent : public IComponent {
protected:
    EntityComponent() = default;

public:
    void Start() override;
    void Execute() override;
    void Stop() override;
};
