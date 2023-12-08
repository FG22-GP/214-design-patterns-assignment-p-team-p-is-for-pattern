#pragma once
#include <functional>
#include <memory>
#include "Entity.h"
#include "math.h"
#include "Vector2D.h"


class Command : std::enable_shared_from_this<Command> {
protected:
    virtual ~Command() = default;

public:
    virtual bool Execute() = 0;
    bool Running;
};


// on update -> we update the oldest command (the first one in the queue)
// if that one's finished, we can update the next one as well (after pop)
// otherwise, we come back next frame and continue executing it

class MoveCommand : public Command, std::enable_shared_from_this<MoveCommand> {
    Vector2D _targetMovement;
    std::shared_ptr<Entity> _target;

public:
    MoveCommand(Vector2D TargetMovement, const std::shared_ptr<Entity>& Receiver) :
        _targetMovement(TargetMovement),
        _target(Receiver) {
        Running = false;
    }

    bool Execute() override {
        _target->position = _targetMovement;
       // printf("calling move");
        return false;
    }
};


class MoveOverTimeCommand : public Command, std::enable_shared_from_this<MoveOverTimeCommand> {
public:
    Vector2D _targetPosition;
    std::shared_ptr<Entity> _target;
    float _duration;

    MoveOverTimeCommand(Vector2D TargetMovement, float Duration, const std::shared_ptr<Entity>& Receiver) :
        _targetPosition(TargetMovement),
        _target(Receiver),
        _duration(Duration) {
        Running = false;
    }

    bool Execute() override { // Todo: needs time class
 
        if (_target->position.GetY() > _targetPosition.GetY()) {
            _target->position = _target->position - Vector2D(0, 1);
       // printf("done with long action");
            return true;
        }
        return false;
    }
};
