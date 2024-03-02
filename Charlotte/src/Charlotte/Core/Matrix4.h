#pragma once

#include "CharCore.h"
#include "Vector3.h"

namespace Charlotte {

    struct CAPI Matrix4 {
        static Matrix4 Identity();

        static Matrix4 Translate(float x, float y, float z);
        static Matrix4 Translate(const Vector3& translation);

        static Matrix4 Scale(float x, float y, float z);
        static Matrix4 Scale(const Vector3& scale);

        static Matrix4 RotateX(float angle);
        static Matrix4 RotateY(float angle);
        static Matrix4 RotateZ(float angle);

        /**
        *   @brief Use degrees for this function, for all other rotate operations
        *   you should use Mathf::Radians(float)
        */
        static Matrix4 RotateEuler(float x, float y, float z);
        static Matrix4 RotateEuler(const Vector3& euler);

        static Matrix4 Ortho(float left, float right, float bottom, float top, float near, float far);
        static Matrix4 Perspective(float fov, float aspect, float near, float far);    

        float m[16];

        Matrix4 operator*(Matrix4 b) {
            Matrix4 res;

            for (uint8_t i = 0; i < 4; i++) {
                for (uint8_t j = 0; j < 4; j++) {
                    res.m[i + j * 4] =
                        m[i + 0 * 4] * b.m[0 + j * 4] +
                        m[i + 1 * 4] * b.m[1 + j * 4] +
                        m[i + 2 * 4] * b.m[2 + j * 4] +
                        m[i + 3 * 4] * b.m[3 + j * 4]; 
                }
            }

            return res;
        }
    };

}