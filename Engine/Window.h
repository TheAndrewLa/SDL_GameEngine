// by andrew.la
#pragma once

#include "SDL.h"
#include "_Definitions.h"
#include <string>

#define DefaultGraphicsMemory (1024)

namespace Engine {
    enum class WindowState {
        Fullscreen, Windowed
    };

    class Window {
    private:
        SDL_Window* m_Window;
        I32 m_StartWidth, m_StartHeight;
        WindowState m_State = WindowState::Windowed;

    public:
        Window(I32, I32, const char*);
        ~Window();

        void MakeFullscreen();
        void MakeWindowed();

        [[nodiscard]] SDL_Window* SDLWindow() const;
        [[nodiscard]] U32 Width() const;
        [[nodiscard]] U32 Height() const;
        [[nodiscard]] WindowState State() const;
    };

    class Graphics {
    private:
        SDL_Renderer* m_Renderer;
        void* m_GraphicsMemory;

    public:
        explicit Graphics(const Window&);
        ~Graphics();

        void SetMainColor(U8 r, U8 g, U8 b, U8 a) const;
        void ClearGraphics() const;
        void PresentGraphics() const;

        [[nodiscard]] void* Memory() const;
        [[nodiscard]] SDL_Renderer* SDLRenderer() const;
    };
}
