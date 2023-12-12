#include "Movement.h"


Vector2D& Movement::ConsumeVelocity() { // we could have slowdown here, this turns it down instantly to zero of consumption
    Vector2D currentVel = Velocity;
    Velocity = Vector2D(0,0);
    return currentVel;
}

Movement::Movement(std::string name, const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
    componentName = name;
}

void Movement::Translate(Vector2D Translation) { // todo: this should be velocity that renderes next frame or something in its update to is beceomes addative,
                                                        // when collision happens we can stop velocity of entity making it fully stop, also we can add other fun
                                                        //stuff like pushback or whatever, this 
    Velocity += Translation;
}

void Movement::Start() {
}

void Movement::Execute() {
    owner->position += ConsumeVelocity();
}

void Movement::Stop() {
}

std::string Movement::GetName() {
    return IComponent::GetName();
}

void Movement::InitializeComponent() {
}