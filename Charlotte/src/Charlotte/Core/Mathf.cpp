#include "Mathf.h"

#include <math.h>

namespace Charlotte::Mathf {

    float Cos(float x) { return cosf(x); }
    
    float Sin(float x) { return sinf(x); }

    float Sqrt(float x) { return sqrtf(x); }

    float Tan(float x) { return tanf(x); }

    float Radians(float x) { return x * (Pi / 180); }

}
