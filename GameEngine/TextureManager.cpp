#include "TextureManager.h"

bool TextureManager::Load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());

	if (loadedSurface == 0)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", fileName.c_str(), IMG_GetError());
		return false;
	}

	SDL_Texture* textureToLoad = NULL;

	textureToLoad = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	if (textureToLoad == 0)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError());
		return false;
	}
	else if (textureToLoad != 0)
	{
		textureMap[id] = textureToLoad;
		return true;
	}


	return false;
}

void TextureManager::Draw(std::string id, SDL_Rect targetRectangle, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{

	SDL_RenderCopyEx(pRenderer, textureMap[id], 0, &targetRectangle, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, SDL_Rect targetRectangle, SDL_Renderer* pRenderer, int currentRow, int currentFrame, SDL_RendererFlip flip)
{

	SDL_Rect srcRect;
	srcRect.x = targetRectangle.w * currentFrame;
	srcRect.y = targetRectangle.h * (currentRow - 1);
	srcRect.w = targetRectangle.w;
	srcRect.h = targetRectangle.h;
	SDL_RenderCopyEx(pRenderer, textureMap[id], &srcRect, &targetRectangle, 0, 0, flip);
}

void TextureManager::ClearFromTextureMap(std::string textureID)
{
	textureMap.erase(textureID);
}


TextureManager* TextureManager::pInstance = 0;