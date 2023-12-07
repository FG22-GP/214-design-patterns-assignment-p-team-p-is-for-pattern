#include "TextureManager.h"

TextureManager::TextureManager()
{
	pRenderer = TheGameWindow::Instance()->GetRenderer();
}


void TextureManager::CleanUpFunction()
{
	for (auto id : textureMap)
	{
		SDL_Texture* textureToDestroy = static_cast<SDL_Texture*>(id.second);
		if (textureToDestroy != nullptr)
		{
			SDL_DestroyTexture(textureToDestroy);
		}
	}
	pInstance = nullptr;
}

bool TextureManager::LoadImage(std::string fileName, std::string id)
{
	SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());

	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", fileName.c_str(), IMG_GetError());
		return false;
	}

	SDL_Texture* textureToLoad = NULL;

	textureToLoad = SDL_CreateTextureFromSurface(pRenderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
	if (textureToLoad == nullptr)
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", fileName.c_str(), SDL_GetError());
		return false;
	}
	else if (textureToLoad != nullptr)
	{
		textureMap[id] = textureToLoad;
		return true;
	}


	return false;
}

//SDLpointer to vector  create your own color thingy maybe 
bool TextureManager::LoadText(std::string fileName, std::string id, Color textColor, int fontSize, std::string text ,Vector2D& dimensions) 
{

	TTF_Font* fontToLoad = TTF_OpenFont(fileName.c_str(), fontSize);

	if (fontToLoad == 0)
	{
		printf("Failed to font:%s SDL_ttf Error: %s\n", fileName.c_str(), TTF_GetError());
		return false;
	}

	SDL_Color tColor;
	tColor.r = textColor.red;
	tColor.g = textColor.green;
	tColor.b = textColor.blue;
	tColor.a = textColor.alpha;


	SDL_Surface* textSurface = TTF_RenderText_Solid(fontToLoad, text.c_str(), tColor);

	if (textSurface == 0)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(pRenderer, textSurface);
	dimensions.SetX(textSurface->w);
	dimensions.SetY(textSurface->h);
	SDL_FreeSurface(textSurface);
	if (textTexture == nullptr)
	{
		printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else if(textTexture != nullptr)
	{
		textureMap[id] = textTexture;
		return true;
	}


	return false;
}

void TextureManager::Draw(std::string id, Vector2D imagePosition, Vector2D imageSize, FlipState flip)
{
	SDL_Rect targetRectangle;
	targetRectangle.x = imagePosition.GetX();
	targetRectangle.y = imagePosition.GetY();
	targetRectangle.w = imageSize.GetX();
	targetRectangle.h = imageSize.GetY();
	SDL_Texture* texture = static_cast<SDL_Texture*>(textureMap[id]);
	if (texture != nullptr)
	{
		SDL_RenderCopyEx(pRenderer, texture, 0, &targetRectangle, 0, 0, MapFlipState( flip));
	}
}

void TextureManager::DrawFrame(std::string id, Vector2D imagePosition, Vector2D imageSize, int currentRow, int currentFrame, FlipState flip)
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
	SDL_Texture* texture = static_cast<SDL_Texture*>(textureMap[id]);
	if (texture != nullptr)
	{
		SDL_RenderCopyEx(pRenderer, texture, 0, &targetRectangle, 0, 0, MapFlipState(flip));
	}
}

void TextureManager::ClearFromTextureMap(std::string textureID)
{
	SDL_Texture* texture = static_cast<SDL_Texture*>(textureMap[textureID]);
	SDL_DestroyTexture(texture);
	textureMap.erase(textureID);
}

SDL_RendererFlip TextureManager::MapFlipState(FlipState flip)
{
	switch (flip)
	{
	case FLIP_NONE:
		return SDL_FLIP_NONE;
	case FLIP_HORIZONTAL:
		return SDL_FLIP_HORIZONTAL;
	case FLIP_VERTICAL:
		return SDL_FLIP_VERTICAL;
	default:
		return SDL_FLIP_NONE;
	}
}


TextureManager* TextureManager::pInstance = 0;