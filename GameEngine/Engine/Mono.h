#pragma once

struct Mono
{
    Mono();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Stop() = 0;
};
