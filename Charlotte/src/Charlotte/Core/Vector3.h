#pragma once

#include "CharCore.h"

namespace Charlotte {

    struct Vector3 {
        float x;
        float y;
        float z;

        Vector3() = default;
        Vector3(const Vector3& copy) = default;

        Vector3(float scalar) : x(scalar), y(scalar), z(scalar) { }
        Vector3(float x, float y, float z) : x(x), y(y), z(z) { }
    };

}