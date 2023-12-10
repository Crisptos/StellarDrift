#include "util.h"
#include "raylib.h"

void StartTimer(Timer *timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

void UpdateTimer(Timer *timer)
{
    // subtract this frame from the timer if it's not allready expired
    if (timer != NULL && timer->lifeTime > 0)
        timer->lifeTime -= GetFrameTime();
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}
