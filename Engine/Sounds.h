// by andrew.la
#pragma once

#include "SDL_mixer.h"
#include "Utils.h"

namespace Engine {
    class Music {
    private:
        Mix_Music* m_Music = nullptr;
        bool m_Playing = false;

        U64 m_InFading = 0;
        U64 m_OutFading = 0;

    public:
        Music() = default;
        explicit Music(const char* path);
        ~Music();

        void SetFading(U64, U64);

        void Play();
        void Stop();

        void Pause();
        void Unpause();
    };

    class Effect {
    private:
        Mix_Chunk* m_Chunk = nullptr;
        I32 m_Channel = -1;

    public:
        Effect() = default;
        explicit Effect(const char* path);
        ~Effect();

        void Play();
        void Stop() const;
    };
}
