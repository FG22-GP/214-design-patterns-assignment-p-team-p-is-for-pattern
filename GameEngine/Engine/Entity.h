#pragma once
#include <vector>

#include "Component.h"
#include "Mono.h"

struct Entity : public Mono
{
    std::vector<Component> components;
};
