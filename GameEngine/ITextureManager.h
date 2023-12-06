#pragma once
#include <iostream>



class ITextureManager
{


protected:
	ITextureManager();

public:

	virtual ~ITextureManager() = default;


	virtual bool LoadImage() = 0;
	virtual bool LoadText() = 0;

	virtual void Draw() = 0;
	virtual void DrawFrame() = 0;

	virtual void ClearFromTextureMap() = 0;

	virtual void CleanUpFunction() = 0;

};

