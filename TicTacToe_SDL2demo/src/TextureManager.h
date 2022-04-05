#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Logger.h"
#include "defs.h"
#include <iostream>
#include <map>
class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (instance == NULL)
		{
			instance = new TextureManager();
		}

		return instance;
	}
	bool load(const char* id, const char* fPath, SDL_Renderer* renderer);
	void draw(const char* id, int x, int y, int w, int h, double scale, double rotFactor, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void removeTexture(const  char* id);
	void clean();
	void genBoard(SDL_Renderer* renderer);
	std::map<const char*, SDL_Texture*> textureMap;

	


private:
	static TextureManager* instance;
	TextureManager(){}
	~TextureManager(){}

};

typedef TextureManager _TextureManager;