// by andrew.la
#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "_Definitions.h"
#include "Window.h"

namespace Engine {
    class Sprite {
    private:
        SDL_Texture* m_Texture;
        I32 m_Width = 0, m_Height = 0;

    public:
        Sprite(const Graphics&, const char*);
        ~Sprite();

        void BlitSprite(const Graphics&, SDL_FRect, F32 = 0);
        void BlitSprite(const Graphics&, SDL_FRect, U8, F32 = 0);
    };
}
