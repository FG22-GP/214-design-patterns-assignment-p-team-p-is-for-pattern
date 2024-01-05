#include "Timer.h"

#include <SDL_timer.h>
#include <vcruntime.h>

Timer* Timer::instance = nullptr;

Timer* Timer::Instance() {
    if (instance == nullptr) {
        instance = new Timer();
    }

    return instance;
}

void Timer::Release() {
    delete instance;
    instance = nullptr;
}

void Timer::Reset() {
    startTicks = SDL_GetTicks();
    elapsedTicks = 0;
    deltaTime = 0.f;
}

float Timer::DeltaTime() {
    return deltaTime;
}

void Timer::TimeScale(float t) {
}

float Timer::TimerScale() {
    return timeScale;
}

void Timer::Update() {
    elapsedTicks = SDL_GetTicks() - startTicks;
    deltaTime = elapsedTicks * 0.001f;
}

Timer::Timer() {
    Reset();
    timeScale = 1.0f;
}

Timer::~Timer() {
}
