#pragma once
#include <memory>
#include "Engine/Entity.h"
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
class Movement;
class IComponent;

class MoveCommand : public Command, std::enable_shared_from_this<MoveCommand> {
    Vector2D _targetMovement;
    std::shared_ptr<Entity> _target;
    std::shared_ptr<Movement> MoveComponent;
    
public:
    
    MoveCommand(Vector2D TargetVelocityNonNormalized, const std::shared_ptr<Entity>& Receiver) :
        _targetMovement(TargetVelocityNonNormalized),
        _target(Receiver)
    {
        Running = false;

        // const std::shared_ptr<IComponent> component = Receiver->GetComponent<IComponent, 0>();
        // const std::shared_ptr<Movement> movementComponent = std::dynamic_pointer_cast<Movement>(component);
        // MoveComponent = movementComponent;
    }

    bool Execute() override {
       // if (MoveComponent) MoveComponent->Translate(_targetMovement);
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

    bool Execute() override { // Todo: needs time class, may be scrapped
        if (!_target->HasComponent("MovementComponent")) return false;
        
        if (_target->position.GetY() > _targetPosition.GetY()) {
            _target->position = _target->position - Vector2D(0, 1);
            return true;
        }
        return false;
    }
};
