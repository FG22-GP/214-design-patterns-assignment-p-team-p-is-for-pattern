#include "GameState.h"

GameState::GameState(GameManager* manager)
{
	gameManager = manager;
}

void GameState::Start()
{
	for (auto entity : entityList)
	{
		entity->Start();
	}
}

void GameState::Stop()
{
	for (auto entity : entityList)
	{
		entity->Stop();
	}

}

void GameState::Update() 
{
	for (auto entity : entityList)
	{
		entity->Update();
	}
}
