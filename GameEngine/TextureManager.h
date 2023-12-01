#pragma once
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL_image.h>
#include <SDL.h>
#include <iostream>
#include <map>
#include <SDL_TTf.h>

class TextureManager
{

public:


	~TextureManager() {}

	bool LoadImage(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	bool LoadText(std::string fileName, std::string id, SDL_Color textColor, 
				  int fontSize, std::string text, SDL_Point& dimensions, SDL_Renderer* pRenderer);

	void Draw(std::string id, SDL_Rect targetRectangle, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, SDL_Rect targetRectangle, SDL_Renderer* pRenderer, int currentRow, int currentFrame,
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

private:

	std::map<std::string, SDL_Texture*> textureMap;

	TextureManager() {}
};


typedef TextureManager TheTextureManager;

#endif
