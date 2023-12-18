#pragma once
#include "GameState.h"
#include "../TextureManager.h"


class Record : public GameState
{
    const std::string stateID = "Record";

    std::shared_ptr<Entity> player;
    std::shared_ptr<Entity> theEnd;
    Vector2D recordingTextSize;

public:
    Record();
    void Start() override;
    void Stop() override;
    void Update() override;

    void Initilize();

    std::string GetStateID() const override { return stateID; }

    ~Record();

};

