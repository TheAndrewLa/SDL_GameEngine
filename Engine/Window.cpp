// by andrew.la
#include "Window.h"

namespace Engine {
    /// Window class
    Window::Window(I32 w, I32 h, const char* title) {
        this->m_StartWidth = w;
        this->m_StartHeight = h;

        this->m_Window = SDL_CreateWindow(title,
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          (I32) w, (I32) h, SDL_WINDOW_SHOWN);
        if (this->m_Window == nullptr) std::exit(1);
    }

    Window::~Window() {
        SDL_DestroyWindow(this->m_Window);
    }

    SDL_Window *Window::SDLWindow() const {
        return this->m_Window;
    }

    U32 Window::Width() const {
        I32 w, h;
        SDL_GetWindowSize(this->m_Window, &w, &h);
        return w;
    }

    U32 Window::Height() const {
        I32 w, h;
        SDL_GetWindowSize(this->m_Window, &w, &h);
        return h;
    }

    void Window::MakeFullscreen() {
        I32 res = SDL_SetWindowFullscreen(this->m_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        if (res == 0) this->m_State = WindowState::Fullscreen;
    }

    void Window::MakeWindowed() {
        I32 res = SDL_SetWindowFullscreen(this->m_Window, 0);
        if (res == 0) {
            SDL_SetWindowBordered(this->m_Window, SDL_TRUE);
            SDL_SetWindowSize(this->m_Window, this->m_StartWidth, this->m_StartHeight);
            this->m_State = WindowState::Windowed;
        }
    }

    WindowState Window::State() const {
        return this->m_State;
    }

    /// Graphics class
    Graphics::Graphics(const Window& window) {
        this->m_Renderer = SDL_CreateRenderer(window.SDLWindow(), -1,
                                              SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        this->m_GraphicsMemory = std::malloc(DefaultGraphicsMemory);

        if (this->m_Renderer == nullptr || this->m_GraphicsMemory == nullptr) std::exit(1);

        SDL_SetRenderDrawBlendMode(this->m_Renderer, SDL_BLENDMODE_BLEND);
    }

    Graphics::~Graphics() {
        SDL_DestroyRenderer(this->m_Renderer);
        std::free(this->m_GraphicsMemory);
    }

    void Graphics::SetMainColor(U8 r, U8 g, U8 b, U8 a) const {
        SDL_SetRenderDrawColor(this->m_Renderer, r, g, b, a);
    }

    void Graphics::ClearGraphics() const {
        SDL_RenderClear(this->m_Renderer);
    }

    void Graphics::PresentGraphics() const {
        SDL_RenderPresent(this->m_Renderer);
    }

    void *Graphics::Memory() const {
        return this->m_GraphicsMemory;
    }

    SDL_Renderer *Graphics::SDLRenderer() const {
        return this->m_Renderer;
    }
}
