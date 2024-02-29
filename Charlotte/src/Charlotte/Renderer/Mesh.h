#pragma once

#include "CharCore.h"
#include "Charlotte/Core/Vector3.h"
#include <vector>

namespace Charlotte {

    struct CAPI Vertex {
        Vector3 Position;

        Vertex(const Vector3& position) : Position(position) { }
    };

    class CAPI Mesh {
        public:
            virtual ~Mesh() = default;
            
            static Ref<Mesh> Create(std::vector<Vertex> vertices, std::vector<uint32_t> triangles);

            virtual void Draw() = 0;
    };

}