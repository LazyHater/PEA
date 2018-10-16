#include "clock.h"

Clock::Clock()
{
}

void Clock::start()
{
    tstart = clock();
    measurement = 0;
}


void Clock::stop()
{
    tstop = clock();
    measurement = ((double)(tstop - tstart))/CLOCKS_PER_SEC;
}

double Clock::read()
{
    return measurement;
}
