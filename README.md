# Project Overview


## Summary
    We created a game which was meant to showcase the  
    command pattern. The goal of the game is to  
    reach the goal in as short of a path as possible.
    We created a very simple level editor which  
    reads from a textfile to create a grid for our game.

## Controls
    You record movement with 'WASD' and press enter  
    to replay what you recorded, try to reach the goal.

## Design Patterns
### Command
- Command.h
### Event Queue
- EventHandler.h
### Singleton
- TextureManager.h/cpp
### Factory
- ComponentCreator.h/cpp
- IComponentFactory.h
- xxCreator.h/cpp
### Component
- IComponent.h
- Render.h/cpp
- Collision.h/cp
- Tile.h/cpp
- Movement.h/cpp
### State
- GameState.h/cpp
- Lose.h/cpp
- PauseState.h/cpp
- PlayState.h/cpp
- Record.h/cpp
- WonState.h/cpp
### Facade 
- Input.h/cpp
### Game Loop
- GameManager.h/cpp
### Subclass Sandbox (maybe)
- Mono.h
- Entity.h/cpp
