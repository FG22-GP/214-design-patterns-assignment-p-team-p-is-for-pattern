#pragma once
#include <functional>
#include <memory>

#include "math.h"
#include "Vector2D.h"



class Entity :  std::enable_shared_from_this<Entity> {
public:
    Vector2D Position;

    Entity() {
        Position = Vector2D(0,0);
    }
    void MoveCharacter(Vector2D translation) {
        Position = translation;
        printf("yo");
    }

    void MoveCharacter(Vector2D translation, float Duration) { // need acturate timer
        
        if (std::abs(translation.GetX() - Position.GetX()) < 10.f && std::abs(translation.GetY() - Position.GetY()) < 10.f) {
            //callback
        }
    }
};

class Command : std::enable_shared_from_this<Command> {
public:
    virtual ~Command() = default;
    virtual void Execute() const = 0;
};

class MoveCommand : public Command, std::enable_shared_from_this<MoveCommand> {
    Vector2D _targetMovement;
    std::shared_ptr<Entity> _target;
    
public:
    MoveCommand(Vector2D TargetMovement, std::shared_ptr<Entity> Receiver) : _targetMovement(TargetMovement), _target(Receiver) {} // fix raw poitners
    void Execute() const override {
        _target->MoveCharacter(this->_targetMovement);
    }
};


class MoveOverTimeCommand : public Command, std::enable_shared_from_this<MoveOverTimeCommand> { 
public:
    Vector2D _targetMovement;
    std::shared_ptr<Entity> _target;
    float _duration;
    
    MoveOverTimeCommand(Vector2D TargetMovement, float Duration, std::shared_ptr<Entity> Receiver) : _targetMovement(TargetMovement), _target(Receiver), _duration(Duration) {}
    void Execute() const override {
        _target->MoveCharacter(_targetMovement, _duration);
    }
};

