#include "GameManager.h"
#include "GameStates/Lose.h"
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"
#include "GameStates/WonState.h"
#include "GameStates/Record.h"
#include "Level/Parser.h"


GameManager::GameManager() {
    gridData = std::make_shared<std::array<std::array<std::array<char, TilemapX>, TilemapY>, 7>>();
    Parser::ReadFromFile(*gridData);

    activeState = nullptr;
    auto arrays = std::make_unique<std::array<std::array<char, TilemapX>, TilemapY>>(gridData->data()[0]);
    activeLevel = std::make_shared<Level>(arrays);
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

void GameManager::RestartLevel(const bool buildNextLevel) {
    if (buildNextLevel) {
        BuildLevel(activeLevel->nextLevelIndex);
        activeLevel->nextLevelIndex++;
    }

    strokes = 0;
    activeLevel->mTime->ResetScore();
    playerEntity->position = activeLevel->grid->entitiesLookup.find("PlayerStartTile")->second->position;
}

void GameManager::BuildLevel(const int index) {
    auto arrays = std::make_unique<std::array<std::array<char, TilemapX>, TilemapY>>(gridData->data()[index]);
    activeLevel = std::make_shared<Level>(arrays);
    activeLevel->nextLevelIndex = index;
}

void GameManager::Update() {
    if (activeState == nullptr) return;

    activeState->Update();
}
