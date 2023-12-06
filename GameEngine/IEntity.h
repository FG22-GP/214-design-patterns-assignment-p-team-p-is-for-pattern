#pragma once
#include "Entity.h"

class IEntity : FakeMono {
protected:
    IEntity();
public:
    virtual ~IEntity();

    Vector2D position;
    std::vector<IComponent> components;

    virtual void Start() override {
        FakeMono::Start();
    }

    virtual void Update() override {
        FakeMono::Update();
    }
    
    virtual void Stop() override {
        FakeMono::Stop();
    }
};
