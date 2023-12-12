#include "GameManager.h"

#include "GameStates/PlayState.h"

#include "GameStates/PauseState.h"
#include "GameStates/PlayState.h"
#include "GameStates/WonState.h"
#include "GameStates/Record.h"


GameManager::GameManager() {
    activeState = nullptr;
	std::shared_ptr<PlayState> playState = std::make_shared<PlayState>();
	PushState(playState);
	std::shared_ptr<PauseState> pauseState = std::make_shared<PauseState>();
	PushState(pauseState);
	std::shared_ptr<WonState> wonState = std::make_shared<WonState>();
	PushState(wonState);
	std::shared_ptr<Record> record = std::make_shared<Record>();
	PushState(record);

}

void GameManager::PushState(std::shared_ptr<GameState> pushState) 
{
	std::cout << "Pushing state with ID: " << pushState->GetStateID() << std::endl;
	allstates[pushState->GetStateID()] = pushState;
}

void GameManager::Start()
{
	for (auto state : allstates)
	{
		state.second->Start();
	}
}

void GameManager::Stop()
{
	for (auto state : allstates)
	{
		state.second->Stop();
	}
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
