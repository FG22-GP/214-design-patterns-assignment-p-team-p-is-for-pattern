#pragma once

struct GameState
{
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update() = 0;
};
