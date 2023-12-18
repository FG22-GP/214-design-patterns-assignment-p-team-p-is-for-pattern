#include "GameManager.h"
#include "GameStates/Lose.h"
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"
#include "GameStates/WonState.h"
#include "GameStates/Record.h"
#include "Level/Parser.h"


GameManager::GameManager(Private): strokes(0) {
}

std::shared_ptr<GameManager> GameManager::Create() {
    return std::make_shared<GameManager>(Private());
}

void GameManager::Initialize(const std::shared_ptr<GameManager> gameManagerPtr) {
    gridData = std::make_shared<std::array<std::array<std::array<char, TilemapX>, TilemapY>, 7>>();
    Parser::ReadFromFile(*gridData);

    activeState = nullptr;
    auto arrays = std::make_unique<std::array<std::array<char, TilemapX>, TilemapY>>(gridData->data()[0]);
    activeLevel = std::make_shared<Level>(arrays);
    for (const auto& entityLookup : activeLevel->grid->entitiesLookup) {
        entityList.insert(entityLookup);
    }

    const auto playState = std::make_shared<PlayState>();
    const auto pauseState = std::make_shared<PauseState>();
    const auto wonState = std::make_shared<WonState>();
    const auto record = std::make_shared<Record>();
    const auto lose = std::make_shared<Lose>();
    playState->SetGameManager(this->GetPtr());
    pauseState->SetGameManager(this->GetPtr());
    wonState->SetGameManager(this->GetPtr());
    record->SetGameManager(this->GetPtr());
    lose->SetGameManager(this->GetPtr());

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

void GameManager::ChangeActiveState(std::string changeID) {
    std::shared_ptr<GameState> stateToChange = allStates[changeID];

    if (stateToChange != nullptr) {
        if (activeState != nullptr) activeState->Stop();
        activeState = stateToChange;
        activeState->Start();
    }
}

void GameManager::RestartLevel(const bool buildNextLevel) {
    if (buildNextLevel) {
        entityList.clear();
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
    for (const auto& entity : activeLevel->grid->entitiesLookup) {
        entityList.insert(entity);
    }
}

std::shared_ptr<Entity> GameManager::GetEntity(const std::string& entityName) {
    if (entityList.contains(entityName)) {
        return entityList.find(entityName)->second;
    }
    return nullptr;
}

std::shared_ptr<GameManager> GameManager::GetPtr() {
    return shared_from_this();
}

void GameManager::Update() {
    if (activeState == nullptr) return;

    activeState->Update();
}
