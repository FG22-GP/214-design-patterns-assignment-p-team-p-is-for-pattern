#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <iostream>
#include <map>

#include <SDL_image.h>
#include <SDL.h>
#include <SDL_TTf.h>

#include "ITextureManager.h"
#include "GameWindow.h"
#include "Vector2D.h"

typedef enum
{
	FLIP_NONE = 0x00000000,      // Do not flip
	FLIP_HORIZONTAL = 0x00000001, // Flip horizontally
	FLIP_VERTICAL = 0x00000002    // Flip vertically
}FlipState;

typedef struct Color
{
	Uint8 red;
	Uint8 green;
	Uint8 blue;
	Uint8 alpha;
}Color;


class TextureManager : public ITextureManager
{

	SDL_Renderer* pRenderer;

	//Need color figure a solution
	//Use vector for points
	
	//Maaaaaybe create your own enums for flipping
	//Modify the Rect to position

	TextureManager();

public:

	~TextureManager() {}

	bool LoadImage() override { return false; }
	bool LoadText() override { return false; }

	void Draw() override {}
	void DrawFrame() override {}

	void ClearFromTextureMap() override {}

	void CleanUpFunction() override;

	bool LoadImage(std::string fileName, std::string id);
	bool LoadText(std::string fileName, std::string id, Color textColor, 
				  int fontSize, std::string text, Vector2D& dimensions);

	void Draw(std::string id, Vector2D imagePosition, Vector2D imageSize, FlipState flip = FLIP_NONE);
	void DrawFrame(std::string id, Vector2D imagePosition, Vector2D imageSize, int currentRow, int currentFrame,
		FlipState flip = FLIP_NONE);

	void ClearFromTextureMap(std::string textureID);

	SDL_RendererFlip MapFlipState(FlipState flip);

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
