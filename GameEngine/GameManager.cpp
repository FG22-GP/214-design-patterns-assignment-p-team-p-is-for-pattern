#include "GameManager.h"

#include "GameStates/PlayState.h"


GameManager::GameManager() : Mono(*this) {
    activeState = nullptr;
}

void GameManager::ChangeState(std::shared_ptr<GameState> pushState) 
{
	std::cout << "Pushing state with ID: " << pushState->GetStateID() << std::endl;
	pushState->Start();
	allstates[pushState->GetStateID()] = pushState;
	pushState->Stop();
}

//void GameManager::PopState()
//{
//	if (gameStates.empty())
//	{
//		return;
//	}
//	gameStates.back()->Stop();
//	gameStates.pop_back();
//
//}

void GameManager::ChangeActiveState(std::string changeID)
{
	std::shared_ptr<GameState> stateToChange = allstates[changeID];

	if (stateToChange !=nullptr )
	{
		if (activeState != nullptr)	activeState->Stop();
		activeState = stateToChange;
		activeState->Start();
	}
	else
	{
		printf("State cannot found");
	}
}

void GameManager::Update()
{
	if (activeState == nullptr)
	{
		return;
	}
	activeState->Update();
}
