#include "Mesh.h"
#include "Charlotte/Core/Log.h"

#ifdef OPENGL
    #include "Charlotte/Platform/OpenGL/GLMesh.h"
#endif

namespace Charlotte {

    Ref<Mesh> Mesh::Create(std::vector<Vertex> vertices, std::vector<uint32_t> triangles) {
        #ifdef OPENGL
            return CreateRef<GLMesh>(vertices, triangles);
        #endif

        LogFatal("Failed to create mesh, no rendering api is defined!");
        return nullptr;
    }

}