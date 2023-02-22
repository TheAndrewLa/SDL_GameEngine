// by andrew.la
#pragma once

#include "SDL_image.h"
#include "Utils.h"
#include "Window.h"
#include "Timer.h"

namespace Engine {
    class Sprite {
    private:
        SDL_Texture* m_Texture = nullptr;
        I32 m_Width = 0, m_Height = 0;

        U8 m_SpriteShading = 0;
        U8 m_SpriteOpacity = 255;

    public:
        Sprite() = default;
        Sprite(const Graphics&, const char*);
        ~Sprite();

        void LoadTexture(const Graphics&, const char*);

        void BlitSprite(const Graphics&, SDL_FRect, F32 = 0);

        [[nodiscard]] bool IsValid() const;
    };

    template <U64 length>
    class AnimatedSprite {
    private:
        Sprite* m_Sequence[length] = {nullptr};
        U64 m_FramesLoaded = 0;
        U64 m_CurrentAnimationIndex = 0;
        U64 m_TicksBetweenFrames = 0;

        Timer m_Timer;

        bool m_Playing = false;

    public:
        explicit AnimatedSprite(U64 ticksBetweenFrames) {
            this->m_TicksBetweenFrames = ticksBetweenFrames;
        }

        void AddFrameToSequence(const Sprite* sprite) {
            if (this->m_FramesLoaded == length || sprite == nullptr) return;
            this->m_Sequence[this->m_FramesLoaded++] = sprite;
        }

        void ReplaceFrameInSequence(U64 index, const Sprite* sprite) {
            if (index >= length || sprite == nullptr) return;
            this->m_Sequence[index] = sprite;
        }

        void BlitSequence(const Graphics& graphics, SDL_FRect rect, F32 angle = 0) {
            this->m_Sequence[this->m_CurrentAnimationIndex]->BlitSprite(graphics, rect, angle);

            if (this->m_Playing || this->m_Timer.GetTicks() >= this->m_TicksBetweenFrames) {
                this->m_CurrentAnimationIndex = (this->m_CurrentAnimationIndex + 1) % length;
            }

        }

        void BlitSequence(const Graphics& graphics, SDL_FRect rect, U8 shading, F32 angle = 0) {
            this->m_Sequence[this->m_CurrentAnimationIndex].BlitSprite(graphics, rect, shading, angle);

            if (this->m_Playing || this->m_Timer.GetTicks() >= this->m_TicksBetweenFrames) {
                this->m_CurrentAnimationIndex = (this->m_CurrentAnimationIndex + 1) % length;
            }
        }

        void Play() {
            this->m_Playing = true;
            this->m_CurrentAnimationIndex = 0;
            this->m_Timer.Start();
        }

        void Stop() {
            this->m_Playing = false;
            this->m_CurrentAnimationIndex = 0;
            this->m_Timer.Stop();
        }

        void Pause() {
            this->m_Playing = false;
            this->m_Timer.Pause();
        }

        void Unpause() {
            this->m_Playing = true;
            this->m_Timer.Unpause();
        }

        [[nodiscard]] U64 GetLength() const {
            return length;
        }

        [[nodiscard]] U64 GetCurrentIndex() const {
            return this->m_CurrentAnimationIndex;
        }
    };
}
