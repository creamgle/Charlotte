#pragma once

#include "CharCore.h"
#include "Charlotte/Renderer/GraphicsContext.h"

/**
    OpenGL context only supports GLFW windows for now
    should definitly have a better system so it can support
    os native windows, mobile, and web builds
*/
struct GLFWwindow;

namespace Charlotte {

    class GLContext : public GraphicsContext {
        public:
            GLContext() = default;
            ~GLContext() override = default;

            bool Initialise(void* handle) override;
            void SwapBuffers() override;
            void Shutdown() override;

        private:
            GLFWwindow* mHandle;
    }; 

}