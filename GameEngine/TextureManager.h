#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <iostream>
#include <map>

#include <SDL_image.h>
#include <SDL.h>
#include <SDL_TTf.h>

#include "GameWindow.h"
#include "Vector2D.h"

class TextureManager
{

	std::map<std::string, SDL_Texture*> textureMap;

	SDL_Renderer* pRenderer;

	//Need color figure a solution
	//Use vector for points
	
	//Maaaaaybe create your own enums for flipping
	//Modify the Rect to position

	TextureManager();

public:


	~TextureManager() {}

	
	//bool LoadImage() override {}
	//bool LoadText() override {}

	//void Draw() override {}
	//void DrawFrame() override {}

	//void ClearFromTextureMap() override {}

	bool LoadImage(std::string fileName, std::string id);
	bool LoadText(std::string fileName, std::string id, SDL_Color textColor, 
				  int fontSize, std::string text, SDL_Point& dimensions);

	void Draw(std::string id, Vector2D imagePosition, Vector2D imageSize, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, Vector2D imagePosition, Vector2D imageSize, int currentRow, int currentFrame,
					SDL_RendererFlip flip = SDL_FLIP_NONE);

	void ClearFromTextureMap(std::string textureID);

	static TextureManager* pInstance;

	static TextureManager* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new TextureManager();
			return pInstance;
		}
		return pInstance;
	}

};


typedef TextureManager TheTextureManager;

#endif
