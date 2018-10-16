#pragma once
#include <ctime>


class Clock
{
    public:
		Clock();
        void start();
        void stop();
        double read();
        double measurement;
    protected:
    private:
        clock_t tstart;
        clock_t tstop;
};

