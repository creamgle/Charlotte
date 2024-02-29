#include "Shader.h"

#ifdef OPENGL
    #include "Charlotte/Platform/OpenGL/GLShader.h"
#endif

#include "Charlotte/Core/Log.h"

namespace Charlotte {

    Ref<Shader> Shader::Create(const std::string& vertex, const std::string& fragment) {
        #ifdef OPENGL
            return CreateRef<GLShader>(vertex, fragment);
        #endif
        LogFatal("Failed to create shader, no rendering api is selected!");
        return nullptr;
    }

}