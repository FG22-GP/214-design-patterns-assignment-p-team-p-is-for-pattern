#pragma once
#include <memory>
#include "string"

class Entity;

class IComponent : public std::enable_shared_from_this<IComponent> {
protected:
    IComponent(const std::shared_ptr<Entity>& Owner);
   
    std::string componentName;
        
    std::shared_ptr<Entity> owner;
public:
    virtual ~IComponent() = default;

    virtual void Start() = NULL;
    virtual void Execute() = NULL;
    virtual void Stop() = NULL;
    virtual std::string GetName();
    virtual void InitializeComponent() = NULL;
    
};
