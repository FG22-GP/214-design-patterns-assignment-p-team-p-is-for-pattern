#include "TextureManager.h"

TextureManager::TextureManager()
{
	pRenderer = TheGameWindow::Instance()->GetRenderer();
}


bool TextureManager::LoadImage(std::string fileName, std::string id)
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

//SDLpointer to vector  create your own color thingy maybe 
bool TextureManager::LoadText(std::string fileName, std::string id, SDL_Color textColor, int fontSize, std::string text ,SDL_Point& dimensions) 
{

	TTF_Font* fontToLoad = TTF_OpenFont(fileName.c_str(), fontSize);

	if (fontToLoad == 0)
	{
		printf("Failed to font:%s SDL_ttf Error: %s\n", fileName.c_str(), TTF_GetError());
		return false;
	}

	SDL_Surface* textSurface = TTF_RenderText_Solid(fontToLoad, text.c_str(), textColor);

	if (textSurface == 0)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
	SDL_FreeSurface(textSurface);
	if (textTexture == 0)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else if(textTexture !=0)
	{
		textureMap[id] = textTexture;
		return true;
	}


	return false;
}

void TextureManager::Draw(std::string id, Vector2D imagePosition, Vector2D imageSize, SDL_RendererFlip flip)
{
	SDL_Rect targetRectangle;
	targetRectangle.x = imagePosition.GetX();
	targetRectangle.y = imagePosition.GetY();
	targetRectangle.w = imageSize.GetX();
	targetRectangle.h = imageSize.GetY();

	SDL_RenderCopyEx(pRenderer, textureMap[id], 0, &targetRectangle, 0, 0, flip);
}

void TextureManager::DrawFrame(std::string id, Vector2D imagePosition, Vector2D imageSize, int currentRow, int currentFrame, SDL_RendererFlip flip)
{
	SDL_Rect targetRectangle;
	targetRectangle.x = imagePosition.GetX();
	targetRectangle.y = imagePosition.GetY();
	targetRectangle.w = imageSize.GetX();
	targetRectangle.h = imageSize.GetY();

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