#include "Matrix4.h"

#include "Mathf.h"

namespace Charlotte {

     Matrix4 Matrix4::Identity() {
        return {
            {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::Translate(float x, float y, float z) {
        return {
            {
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                x, y, z, 1
            }
        };
    }

    Matrix4 Matrix4::Translate(const Vector3& translation) {
        return Translate(translation.x, translation.y, translation.z);
    }

    Matrix4 Matrix4::Scale(float x, float y, float z) {
        return {
            {
                x, 0, 0, 0,
                0, y, 0, 0,
                0, 0, z, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::Scale(const Vector3& scale) {
        return Scale(scale.x, scale.y, scale.z);
    }

    Matrix4 Matrix4::RotateX(float angle) {
        float s = Mathf::Sin(angle);
        float c = Mathf::Cos(angle);

        return {
            {
                1, 0, 0, 0,
                0, c,-s, 0,
                0, s, c, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::RotateY(float angle) {
        float s = Mathf::Sin(angle);
        float c = Mathf::Cos(angle);

        return {
            {
                c, 0, s, 0,
                0, 1, 0, 0,
               -s, 0, c, 0,
                0, 0, 0, 1
            }
        };
    }

    Matrix4 Matrix4::RotateZ(float angle) {
        float s = Mathf::Sin(angle);
        float c = Mathf::Cos(angle);

        return {
            {
                c, s, 0, 0,
               -s, c, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1 
            }
        };
    } 

    Matrix4 Matrix4::RotateEuler(float x, float y, float z) {
        // Not the most effecient way, should definily rewrite to be better
        return RotateX(Mathf::Radians(x)) * RotateY(Mathf::Radians(y)) * RotateZ(Mathf::Radians(z));
    }

    Matrix4 Matrix4::RotateEuler(const Vector3& euler) {
        return RotateEuler(euler.x, euler.y, euler.z);
    }

    Matrix4 Matrix4::Ortho(float left, float right, float bottom, float top, float near, float far) {
        float m00 = 2.0f / (right - left);
        float m11 = 2.0f / (top - bottom);
        float m22 = -2.0f / (far - near);

        float x = -(right + left) / (right - left);
        float y = -(top + bottom) / (top - bottom);
        float z = -(far + near) / (far - near);

        return {
            {
                m00, 0, 0, 0,
                0, m11, 0, 0,
                0, 0, m22, 0,
                x, y, z, 1
            }
        };
    }

    Matrix4 Matrix4::Perspective(float fov, float aspect, float near, float far) {
        float tanHalfFov = Mathf::Tan(fov * 0.5f);    
        return {
            {
                1.0f / (aspect * tanHalfFov), 0, 0, 0,
                0, 1.0f / tanHalfFov, 0, 0,
                0, 0, -(far + near) / (far - near), -1,
                0, 0, (-2.0f * far * near) / (far - near), 0
            }
        };
    }


}