#pragma once

#include "CharCore.h"
#include "Charlotte/Core/Matrix4.h"
#include "Charlotte/Core/Vector3.h"

namespace Charlotte {

    /**
        Transform component, used to give entities
        position, rotation, and scale values,
        also can create a model matrix using
        Transform::CreateModel(Transform)
    */
    struct CAPI Transform {
        static Matrix4 CreateModel(Transform transform);

        Vector3 Position;
        // TODO: Rotation using quaternions or euler
        Vector3 Scale;

        Transform() = default;
        Transform(const Transform& copy) = default;

        Transform(const Vector3& position) : Position(position), Scale((Vector3){ 1.0f }) {}
        Transform(const Vector3& position, const Vector3& scale) : Position(position), Scale(scale) { }
    };

}