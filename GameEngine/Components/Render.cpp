#include "Render.h"

Render::Render(const std::shared_ptr<Entity>& Owner) : IComponent(Owner) {
}

void Render::Start() {
}

void Render::Execute() {
}

void Render::Stop() {
}

std::string Render::GetName() {
    return IComponent::GetName();
}

void Render::InitializeComponent() {
}
