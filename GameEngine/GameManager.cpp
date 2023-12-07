#include "GameManager.h"

#include "GameStates/PlayState.h"


GameManager::GameManager()
{

}

void GameManager::PushState(std::shared_ptr<GameState> pushState)
{
	gameStates.push_back(pushState);
	gameStates.back()->Start();
}

void GameManager::PopState()
{
	if (gameStates.empty())
	{
		return;
	}
	gameStates.back()->Stop();
	gameStates.pop_back();

}

void GameManager::ChangeState(std::shared_ptr<GameState> changeState)
{
	if (!gameStates.empty())
	{
		if (gameStates.back()->GetStateID() == changeState->GetStateID())
		{
			return;
		}
		gameStates.back()->Stop();
		gameStates.pop_back();
	}
	gameStates.push_back(changeState);
	gameStates.back()->Start();
}

void GameManager::Update()
{
	if (gameStates.empty())
	{
		return;
	}
	gameStates.back()->Update();
}

