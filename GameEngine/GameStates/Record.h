#pragma once
#include "GameState.h"


class Record : public GameState
{
    const std::string stateID = "Record";


public:
    Record() {}
    void Start() override;
    void Stop() override;
    void Update() override;

    std::string GetStateID() const override { return stateID; }

    ~Record() {}

};

