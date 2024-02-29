#include "GraphicsContext.h"
#include "CharCore.h"
#include "Charlotte/Core/Log.h"

#ifdef OPENGL
    #include "Charlotte/Platform/OpenGL/GLContext.h"
#endif

namespace Charlotte {

    Scope<GraphicsContext> GraphicsContext::Create() {
        #ifdef OPENGL
            return CreateScope<GLContext>();
        #endif

        LogFatal("Failed to create a graphics context, possible because you havent defined a rendering api!");
        LogFatal("  use OPENGL define to use OpenGL.");
        return nullptr;
    }

}