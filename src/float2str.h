#ifndef float2str_h
#define float2str_h

#include <tice.h>

void float2str(float value, char *str)
{
    real_t tmp_real = os_FloatToReal(value);
    os_RealToStr(str, &tmp_real, -1, 1, 8);
}

#endif