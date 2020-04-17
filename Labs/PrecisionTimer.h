/* A much more precsion timer found in github */

#ifndef _PRECISIONTIMER_H_
#define _PRECISIONTIMER_H_

#include <windows.h>

class PrecisionTimer
{
    LARGE_INTEGER lFreq, lStart;

public:
    PrecisionTimer()
    {
        QueryPerformanceFrequency(&lFreq);
    }

    inline void Start()
    {
        QueryPerformanceCounter(&lStart);
    }

    inline double Stop()
    {
        // Return duration in seconds...
        LARGE_INTEGER lEnd;
        QueryPerformanceCounter(&lEnd);
        return (double(lEnd.QuadPart - lStart.QuadPart) / lFreq.QuadPart);
    }
};

#endif // _PRECISIONTIMER_H_
