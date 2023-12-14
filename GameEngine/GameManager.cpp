#include "GameManager.h"
#include "GameStates/Lose.h"
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"
#include "GameStates/WonState.h"
#include "GameStates/Record.h"


GameManager::GameManager() {
    activeState = nullptr;
    activeLevel = std::make_shared<Level>(Level());

    const auto playState = std::make_shared<PlayState>(this);
    const auto pauseState = std::make_shared<PauseState>(this);
    const auto wonState = std::make_shared<WonState>(this);
    const auto record = std::make_shared<Record>(this);
    const auto lose = std::make_shared<Lose>(this);
    
    PushState(playState);
    PushState(pauseState);
    PushState(wonState);
    PushState(record);
    PushState(lose);
}

void GameManager::PushState(std::shared_ptr<GameState> pushState) {
    std::cout << "Pushing state with ID: " << pushState->GetStateID() << std::endl;
    allStates[pushState->GetStateID()] = pushState;
}

void GameManager::Start() {
    for (auto state : allStates) {
        state.second->Start();
    }
}

void GameManager::Stop() {
    for (auto state : allStates) {
        state.second->Stop();
    }
}

void GameManager::ChangeActiveState(std::string changeID, bool shouldPassEntites) {
    std::shared_ptr<GameState> stateToChange = allStates[changeID];

    if (stateToChange != nullptr) {
        if (activeState != nullptr) activeState->Stop();
        if (shouldPassEntites) {
            stateToChange->entityList = activeState->entityList;
        }
        activeState = stateToChange;
        activeState->Start();
    }
}

void GameManager::RestartLevel(const bool generateNewLevel) {
    if (generateNewLevel) {
        activeLevel->GenerateRandomLevel();
    }

    strokes = 0;
    activeLevel->score->ResetScore();
    playerEntity->position = activeLevel->GetStartPosition();
}

void GameManager::Update() {
    if (activeState == nullptr) return;

    activeState->Update();
}
