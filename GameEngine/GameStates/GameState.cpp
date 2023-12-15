#include "GameState.h"

GameState::GameState(GameManager* manager)
{
	gameManager = manager;
}

void GameState::Start()
{
	for (auto entity : entityList)
	{
		entity.second->Start();
	}
}

void GameState::Stop()
{
	for (auto entity : entityList)
	{
		entity.second->Stop();
	}

}

void GameState::Update() 
{
	for (auto entity : entityList)
	{
		entity.second->Update();
	}
}
