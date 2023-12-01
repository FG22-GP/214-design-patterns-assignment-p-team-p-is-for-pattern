//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Input.h"
#include "IGameWindow.h"
#include "GameWindow.h"


//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

const char* pikachuImagePath{ "img/pikachu.png" };

int main(int argc, char* args[])
{
	const auto game_window = new GameWindow(1024, 768, IMG_INIT_PNG);
	std::string KeysToRegister[] = {"LEFT", "RIGHT", "UP", "DOWN", "W", "A", "S", "D", "ENTER", "RETURN", "ESCAPE", "SPACE"};
	Input::RegisterKeys(KeysToRegister, std::size(KeysToRegister));
	// All data related to pikachu
	SDL_Texture* pikachu = NULL; // The final optimized image
	bool pikachuMoveRight = false;
	int pik_x, pik_y;
	pik_x = pik_y = 0;
	int pik_w, pik_h;
	pik_w = pik_h = 200;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(pikachuImagePath);
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", pikachuImagePath, IMG_GetError());
		return -1;
	}
	else
	{
		//Convert surface to screen format
		pikachu = SDL_CreateTextureFromSurface(game_window->GetRenderer(), loadedSurface);
		if (pikachu == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", pikachuImagePath, SDL_GetError());
			return -1;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	// load font
	auto font = TTF_OpenFont("font/lazy.ttf", 100);
	if (font == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return -1;
	}

	// create text from font
	SDL_Color textColor = { 0xff, 0xff, 0xff };
	//Render text surface
	SDL_Texture* textTexture; // The final optimized image

	// render the text into an unoptimized CPU surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, "The lazy fox, blah blah", textColor);
	int textWidth, textHeight;
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return -1;
	}
	else
	{
		// Create texture GPU-stored texture from surface pixels
		textTexture = SDL_CreateTextureFromSurface(game_window->GetRenderer(), textSurface);
		if (textTexture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
			return -1;
		}
		// Get image dimensions
		auto width = textSurface->w;
		auto height = textSurface->h;
		textWidth = textSurface->w;
		textHeight = textSurface->h;
		//Get rid of old loaded surface
		SDL_FreeSurface(textSurface);
	}

	bool quit = false;

	// while the user doesn't want to quit
	while (quit == false)
	{
		SDL_GetTicks();
		Input::UpdateInput();
		
		if (Input::GetKey("W") || Input::GetKey("UP")) pik_y--;
		if (Input::GetKey("S") || Input::GetKey("DOWN")) pik_y++;
		if (Input::GetKey("D") || Input::GetKey("RIGHT")) pik_x++;
		if (Input::GetKey("A") || Input::GetKey("LEFT")) pik_x--;
		
		// clear the screen
		game_window->Clear();
		
		// render Pikachu
		SDL_Rect targetRectangle{
			pik_x,
			pik_y,
			pik_w,
			pik_h
		};
		SDL_RenderCopy(game_window->GetRenderer(), pikachu, NULL, &targetRectangle);

		// render the text
		targetRectangle = SDL_Rect{
			500,
			500,
			textWidth,
			textHeight
		};
		SDL_RenderCopy(game_window->GetRenderer(), textTexture, NULL, &targetRectangle);

		// present screen (switch buffers)
		game_window->Present();
		
		SDL_Delay(3); // can be used to wait for a certain amount of ms
	}

	return 0;
}