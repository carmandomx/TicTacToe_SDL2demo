#include "TextureManager.h"
TextureManager* TextureManager::instance = 0;

bool TextureManager::load(const char* id, const char* fPath, SDL_Renderer* renderer)
{
    SDL_Texture* tex = IMG_LoadTexture(renderer, fPath);
    if (tex == NULL)
    {

        return false;
    }

    textureMap[id] = tex;

    return true;
}

void TextureManager::draw(const char* id, int x, int y, int w, int h, double scale, double rotFactor, SDL_Renderer* renderer, SDL_RendererFlip flip)
{
    SDL_Rect srcRect, dstRect;
    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = dstRect.w = w;
    srcRect.h = dstRect.h = h;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w *= scale;
    dstRect.h *= scale;

    SDL_RenderCopyEx(renderer, textureMap[id], &srcRect, &dstRect, rotFactor, NULL, flip);

    return;
}

void TextureManager::removeTexture(const char* id)
{
    textureMap.erase(id);
}

void TextureManager::clean()
{
    for (auto const& [k, v] : textureMap)
    {
        SDL_DestroyTexture(v);
    }
}

void TextureManager::genBoard(SDL_Renderer *renderer)
{
    double scale = 2.0;
    int initX = WIN_WIDTH / 3;
    int initY = WIN_HEIGHT / 3;
    int offset = 31 * scale;
    _TextureManager::Instance()->draw("tileSet1", initX, initY, 32, 32, scale, 0, renderer);
    _TextureManager::Instance()->draw("tileSet1", initX, initY, 32, 32, scale, 90.0, renderer, SDL_FLIP_VERTICAL);
    _TextureManager::Instance()->draw("tileSet1", initX + offset, initY, 32, 32, scale, 0, renderer);
    _TextureManager::Instance()->draw("tileSet1", initX + offset, initY, 32, 32, scale, 90.0, renderer, SDL_FLIP_VERTICAL);
    _TextureManager::Instance()->draw("tileSet1", initX + offset * 2, initY, 32, 32, scale, 0, renderer);
    _TextureManager::Instance()->draw("tileSet1", initX, initY + offset, 32, 32, scale, 0, renderer);
    _TextureManager::Instance()->draw("tileSet1", initX, initY + offset, 32, 32, scale, 90.0, renderer, SDL_FLIP_VERTICAL);
    _TextureManager::Instance()->draw("tileSet1", initX + offset, initY + offset, 32, 32, scale, 0, renderer);
    _TextureManager::Instance()->draw("tileSet1", initX + offset, initY + offset, 32, 32, scale, 90.0, renderer, SDL_FLIP_VERTICAL);
    _TextureManager::Instance()->draw("tileSet1", initX + offset * 2, initY + offset, 32, 32, scale, 0, renderer);

    _TextureManager::Instance()->draw("tileSet1", initX, initY + offset * 2, 32, 32, 2, 90.0, renderer, SDL_FLIP_VERTICAL);

    _TextureManager::Instance()->draw("tileSet1", initX + offset, initY + offset * 2, 32, 32, 2, 90.0, renderer, SDL_FLIP_VERTICAL);
}
