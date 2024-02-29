#include "RendererApi.h"

#include "Charlotte/Core/Log.h"

#ifdef OPENGL
    #include "Charlotte/Platform/OpenGL/GLApi.h"
#endif

namespace Charlotte {

    Ref<RendererApi> RendererApi::Create() {
        #ifdef OPENGL
            return CreateRef<GLApi>();
        #endif
        LogFatal("Failed to get rendering api!");
        return nullptr;
    }

}