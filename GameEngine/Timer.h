#pragma once

class Timer {
    static  Timer* instance;

    unsigned int startTicks;
    unsigned int elapsedTicks;
    float deltaTime;
    float timeScale;
public:

    static Timer* Instance();
    static void Release();

    void Reset();
    float DeltaTime();

    void TimeScale(float t);
    float TimerScale();

    void Update();

private:
    Timer();
    ~Timer();
};
