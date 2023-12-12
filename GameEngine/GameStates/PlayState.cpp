#include "PlayState.h"
#include "..\Vector2D.h"

#include "..\Components\Render.h"
#include "..\Engine\RenderCreator.h"

//const std::string PlayState::stateID = "Play";

PlayState::PlayState()
{
    std::shared_ptr<Entity> player= std::make_shared<Entity>(Vector2D(200,200));
    auto componentCreator = RenderCreator();
    player->AddComponent(componentCreator.CreateComponent(player,Vector2D(200,200),"pikachu"));
    entityList.push_back(player);
}

void PlayState::Start()
{
    //State Start logic here

    
    printf("Play State Entered \n");
    //runs entity Start logic
    GameState::Start();

}

void PlayState::Stop()
{
    //State Stop logic here

    printf("Play Stopped Entered \n");
    //runs entity Stop logic
    GameState::Stop();
}

void PlayState::Update()
{
    //State Update logic here

    //runs entity Update logic
    GameState::Update();
}

PlayState::~PlayState()
{
    TheTextureManager::Instance()->ClearFromTextureMap("pikachu");
}
