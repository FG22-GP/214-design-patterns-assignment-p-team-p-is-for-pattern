#pragma once
#include <functional>
#include "Vector2D.h"

class Receiver {
public:
    template<typename  T>
    void Execute(T data) {

    }
};

class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() const = 0;
};

class MoveCommand : public Command {
    Vector2D _targetMovement;
    Receiver* _target;
    
public:
    MoveCommand(Vector2D TargetMovement, Receiver* Receiver) : _targetMovement(TargetMovement), _target(Receiver) {}
    void Execute() const override {
        _target->Execute(this);
    }
};


class MoveOverTimeCommand : public Command { // 
public:
    Vector2D _targetMovement;
    Receiver* _target;
    float _duration;
    
    MoveOverTimeCommand(Vector2D TargetMovement, float duration, Receiver* Receiver) : _targetMovement(TargetMovement), _target(Receiver), _duration(duration) {}
    void Execute() const override {
        _target->Execute(this);
    }
};

