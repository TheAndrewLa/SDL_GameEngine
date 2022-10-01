// by andrew.la
#include "Sprite.h"

namespace Engine {
    Sprite::Sprite(const Graphics& graphics, const char* path) {
        this->m_Texture = IMG_LoadTexture(graphics.SDLRenderer(), path);
        SDL_QueryTexture(this->m_Texture, nullptr, nullptr, &this->m_Width, &this->m_Height);
    }

    Sprite::~Sprite() {
        SDL_DestroyTexture(this->m_Texture);
    }

    void Sprite::BlitSprite(const Graphics& graphics, SDL_FRect rect, F32 angle) {
        SDL_Rect rect1 = {0, 0, this->m_Width, this->m_Height};
        SDL_FRect rect2 = rect;

        SDL_RenderCopyExF(graphics.SDLRenderer(), this->m_Texture, &rect1, &rect2,
                          (F64) angle, nullptr, SDL_FLIP_NONE);
    }

    void Sprite::BlitSprite(const Graphics& graphics, SDL_FRect rect, U8 shading, F32 angle) {
        auto black = 255 - shading;
        SDL_Rect rect1 = {0, 0, this->m_Width, this->m_Height};
        SDL_FRect rect2 = rect;

        SDL_SetTextureColorMod(this->m_Texture, black, black, black);
        SDL_RenderCopyExF(graphics.SDLRenderer(), this->m_Texture, &rect1, &rect2,
                          (F64) angle, nullptr, SDL_FLIP_NONE);
    }
}
