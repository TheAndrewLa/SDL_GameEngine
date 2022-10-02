// by andrew.la
#pragma once

#include "SDL.h"
#include "_Definitions.h"

namespace Engine {
    class Timer {
    private:
        U64 m_Ticks = 0;
        U64 m_PausedTicks = 0;
        bool m_Run = false;
        bool m_Paused = false;

    public:
        Timer() = default;

        void Start();
        U64 Stop();
        U64 Pause();
        U64 Unpause();

        [[nodiscard]] U64 GetTicks() const;

        static U64 TicksToMilliseconds(U64);
        static F32 TicksToSeconds(U64);
        static F32 TicksToMinutes(U64);
    };
}
