#pragma once
#include "GameState.h"
#include "../TextureManager.h"


class Record : public GameState
{
    const std::string stateID = "Record";

    std::shared_ptr<Entity> player;
    std::shared_ptr<Entity> theEnd;
    Vector2D recordingTextSize;
    Vector2D scoreTextSize;
    Color scoreRedTextColour = {0x80, 0x00, 0x00};
    Color scoreGreenTextColour = {0x00, 0x80, 0x00};
    Color scoreTextColour = {0xff, 0xff, 0xff};
public:
    Record();
    void Start() override;
    void Stop() override;
    void Update() override;

    void Initilize();

    std::string GetStateID() const override { return stateID; }

    ~Record();

};

