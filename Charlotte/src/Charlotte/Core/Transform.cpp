#include "Transform.h"
#include "Charlotte/Core/Matrix4.h"

namespace Charlotte {

    Matrix4 Transform::CreateModel(Transform transform) {
        // TODO: Maybe more optimized matrix operation, that doesnt
        // envolve matrix multiplication
        return Matrix4::Translate(transform.Position) * Matrix4::Scale(transform.Scale);
    }

}