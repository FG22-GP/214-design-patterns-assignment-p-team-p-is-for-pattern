#include "GameManager.h"
#include "GameStates/Lose.h"
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"
#include "GameStates/WonState.h"
#include "GameStates/Record.h"


GameManager::GameManager() {
    activeState = nullptr;

    std::shared_ptr<PlayState> playState = std::make_shared<PlayState>(this);
    std::shared_ptr<PauseState> pauseState = std::make_shared<PauseState>(this);
    std::shared_ptr<WonState> wonState = std::make_shared<WonState>(this);
    std::shared_ptr<Record> record = std::make_shared<Record>(this);
    std::shared_ptr<Lose> lose = std::make_shared<Lose>(this);

    PushState(playState);
    PushState(pauseState);
    PushState(wonState);
    PushState(record);
    PushState(lose);
}

void GameManager::PushState(std::shared_ptr<GameState> pushState) {
    std::cout << "Pushing state with ID: " << pushState->GetStateID() << std::endl;
    allstates[pushState->GetStateID()] = pushState;
}

void GameManager::Start() {
    for (auto state : allstates) {
        state.second->Start();
    }
}

void GameManager::Stop() {
    for (auto state : allstates) {
        state.second->Stop();
    }
}

void GameManager::ChangeActiveState(std::string changeID, bool shouldPassEntites) {
    std::shared_ptr<GameState> stateToChange = allstates[changeID];

    if (stateToChange != nullptr) {
        if (activeState != nullptr) activeState->Stop();
        if (shouldPassEntites) {
            stateToChange->entityList = activeState->entityList;
        }
        activeState = stateToChange;
        activeState->Start();
    }
    
}

void GameManager::Update() {
    if (activeState == nullptr) return;
    
    activeState->Update();
}
