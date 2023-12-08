#pragma once

class Mono
{
public:
    virtual ~Mono() = default;
    Mono();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Stop() = 0;
};
