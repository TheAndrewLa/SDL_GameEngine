// by andrew.la
#include "Sounds.h"

namespace Engine {
    Music::Music(const char *path) {
        this->m_Music = Mix_LoadMUS(path);
    }

    Music::~Music() {
        if (this->m_Music != nullptr) Mix_FreeMusic(this->m_Music);
    }

    void Music::SetFading(U64 in, U64 out) {
        this->m_InFading = in;
        this->m_OutFading = out;
    }

    void Music::Play() {
        if (this->m_Music == nullptr) return;

        Mix_FadeInMusic(this->m_Music, 0, (I32) this->m_InFading);
        this->m_Playing = true;
    }

    void Music::Stop() {
        if (this->m_Music == nullptr) return;

        Mix_FadeOutMusic((I32) this->m_OutFading);
        this->m_Playing = false;
    }

    void Music::Pause() {
        Mix_PauseMusic();
        this->m_Playing = false;
    }

    void Music::Unpause() {
        Mix_ResumeMusic();
        this->m_Playing = true;
    }

    Effect::Effect(const char *path) {
        this->m_Chunk = Mix_LoadWAV(path);
        this->m_Channel = Mix_AllocateChannels(1);
    }

    Effect::~Effect() {
        if (this->m_Chunk != nullptr) Mix_FreeChunk(this->m_Chunk);
    }

    void Effect::Play() {
        if (this->m_Chunk != nullptr) Mix_PlayChannel(this->m_Channel, this->m_Chunk, 0);
    }

    void Effect::Stop() const {
        Mix_HaltChannel(this->m_Channel);
    }
}
