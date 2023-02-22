// by andrew.la
#include "SDL_ttf.h"

#include "Engine/Window.h"
#include "Engine/Sprite.h"
#include "Engine/Timer.h"
#include "Engine/Sounds.h"

bool running;
void PollEvents(Engine::Window& window) {
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) running = false;
    }
}

void InitSDLSystems() {
    int res0 = SDL_Init(SDL_INIT_EVERYTHING);
    int res1 = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    int res2 = TTF_Init();
    int res3 = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,
                             16384);

    if (res0 < 0) exit(1);
    if (!(res1 & (IMG_INIT_PNG | IMG_INIT_JPG))) exit(1);
    if (res2 < 0) exit(1);
    if (res3 < 0) exit(1);
}

void CloseSDLSystems() {
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[]) {
    InitSDLSystems();
    Engine::Window window(1280, 720, "Window");
    window.MakeFullscreen();

    Engine::Graphics graphics(window);

    running = true;
    while (running) {
        PollEvents(window);

        graphics.SetMainColor(255, 100, 100, 255);
        graphics.ClearGraphics();

        graphics.PresentGraphics();

        SDL_Delay(10);
    }

    CloseSDLSystems();
    return 0;
}
