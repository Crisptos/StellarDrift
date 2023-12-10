#pragma once
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define BTN_WIDTH_WIDE 150
#define BTN_WIDTH 100
#define BTN_HEIGHT 20

#define TEXT_FIELD_WIDTH 200
#define TEXT_FIELD_HEIGHT 20

// Timer Functionality _________________________________________
typedef struct Timer
{
    double startTime; // Start time (seconds)
    double lifeTime;  // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime);
void UpdateTimer(Timer *timer);
bool TimerDone(Timer timer);
double GetElapsed(Timer timer);
// Timer Functionality _________________________________________
