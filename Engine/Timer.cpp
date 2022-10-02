// by andrew.la
#include "Timer.h"

namespace Engine {
    void Timer::Start() {
        this->m_Run = true;
        this->m_Paused = false;
        this->m_Ticks = SDL_GetTicks64();
    }

    U64 Timer::Stop() {
        this->m_Run = false;
        this->m_Paused = false;

        return (SDL_GetTicks64() - this->m_Ticks);
    }

    U64 Timer::Pause() {
        this->m_Run = false;
        this->m_Paused = true;
        this->m_PausedTicks = SDL_GetTicks64();

        return (SDL_GetTicks64() - this->m_Ticks);
    }

    U64 Timer::Unpause() {
        this->m_Run = true;
        this->m_Paused = false;

        return (SDL_GetTicks64() - this->m_PausedTicks);
    }

    U64 Timer::GetTicks() const {
        return (SDL_GetTicks64() - this->m_Ticks);
    }

    U64 Timer::TicksToMilliseconds(U64 ticks) {
        return ticks;
    }

    F32 Timer::TicksToSeconds(U64 ticks) {
        return ((F32) ticks) / (1000.0f);
    }

    F32 Timer::TicksToMinutes(U64 ticks) {
        return ((F32) ticks) / (60000.0f);
    }
}
