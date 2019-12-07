#pragma once
#include <SDL.h>
#include <iostream>

class Time
{
private:
    Uint32 current_time;

public:
    Time();

    Uint32 get_Time();

    bool check_Time(Uint32);

    void Time_Delay(Uint32);
};