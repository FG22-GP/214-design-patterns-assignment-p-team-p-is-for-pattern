#pragma once

struct Component
{
    bool bEnabled;

    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Update() = 0;
};
