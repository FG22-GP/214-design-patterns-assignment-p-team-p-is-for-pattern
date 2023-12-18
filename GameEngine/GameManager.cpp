#include "GameManager.h"

#include "EventHandler.h"
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
        entityMap.insert(entityLookup);
    }

    const auto playState = std::make_shared<PlayState>();
    const auto pauseState = std::make_shared<PauseState>();
    const auto wonState = std::make_shared<WonState>();
    const auto record = std::make_shared<Record>();
    const auto lose = std::make_shared<Lose>();
    playState->SetGameManager(gameManagerPtr->GetPtr());
    pauseState->SetGameManager(gameManagerPtr->GetPtr());
    wonState->SetGameManager(gameManagerPtr->GetPtr());
    record->SetGameManager(gameManagerPtr->GetPtr());
    lose->SetGameManager(gameManagerPtr->GetPtr());


    Vector2D startPosition = entityMap.find("PlayerStartTile")->second->position;
    auto player = std::make_shared<Entity>("Player", startPosition);
    playerEntity = player;

    player->AddComponent(RenderCreator().CreateComponent(player, Vector2D(32, 32), "MainCharacterSolo"));
    player->AddComponent(MovementCreator().CreateComponent(player, 400.f));
    player->AddComponent(CollisionCreator().CreateComponent(player, 32.0f, 32.0f));

    entityMap.insert(std::make_pair(player->GetEntityName(), player));


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
    for (auto kvp : entityMap) if (kvp.second) kvp.second->Start();
    for (auto state : allStates) {
        state.second->Start();
    }
}

void GameManager::Stop() {
    for (auto kvp : entityMap) if (kvp.second) kvp.second->Stop();
    for (auto state : allStates) {
        state.second->Stop();
    }
}

void GameManager::Update() {
    if (activeState == nullptr) return;

    for (auto kvp : entityMap) if (kvp.second) kvp.second->Update();

    activeState->Update();

}

void GameManager::ChangeActiveState(std::string changeID) {
    std::shared_ptr<GameState> stateToChange = allStates[changeID];

    if (stateToChange != nullptr) {
        if (activeState != nullptr) activeState->Stop();
        activeState = stateToChange;
        activeState->Start();
    }
}

void GameManager::CleanEntities() {
    std::erase_if(entityMap,[](const std::pair<std::string, std::shared_ptr<Entity>>& entity){return entity.second->GetEntityName() != "Player";});
}



void GameManager::RestartLevel(const bool buildNextLevel) {
    if (buildNextLevel) {
        CleanEntities();
        activeLevel->levelIndex++;
        BuildLevel(activeLevel->levelIndex);
    }

    
    strokes = 0;
    EventHandler::Clear();
    activeLevel->mTime->ResetScore();
    playerEntity->position = activeLevel->grid->entitiesLookup.find("PlayerStartTile")->second->position;
}

void GameManager::BuildLevel(const int index) {
    auto arrays = std::make_unique<std::array<std::array<char, TilemapX>, TilemapY>>(gridData->data()[index]);
    activeLevel = std::make_shared<Level>(arrays);
    activeLevel->levelIndex = index;
    for (const auto& entity : activeLevel->grid->entitiesLookup) {
        entityMap.insert(entity);
    }
}

std::shared_ptr<Entity> GameManager::GetEntity(const std::string& entityName) {
    if (entityMap.contains(entityName)) {
        return entityMap.find(entityName)->second;
    }
    return nullptr;
}

std::shared_ptr<GameManager> GameManager::GetPtr() {
    return shared_from_this();
}
