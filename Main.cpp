// by andrew.la
#include "SDL_ttf.h"

#include "Engine/Window.h"
#include "Engine/Sprite.h"

bool running;
void PollEvents(Engine::Window& window) {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) running = false;
        if (event.type == SDL_KEYUP && event.key.keysym.scancode == SDL_SCANCODE_F11) {
            if (window.State() == Engine::WindowState::Fullscreen) window.MakeWindowed();
            else if (window.State() == Engine::WindowState::Windowed) window.MakeFullscreen();
        }
    }
}

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    Engine::Window window(1280, 720, "Window");
    Engine::Graphics graphics(window);

    running = true;
    while (running) {
        PollEvents(window);

        graphics.SetMainColor(255, 100, 100, 255);
        graphics.ClearGraphics();

        graphics.PresentGraphics();

        SDL_Delay(10);
    }

    SDL_Quit();
    return 0;
}
