#include "GLContext.h"
#include "Charlotte/Core/Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Charlotte {

    bool GLContext::Initialise(void* handle) {
        mHandle = static_cast<GLFWwindow*>(handle);
        glfwMakeContextCurrent(mHandle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            LogError("Failed to load OpenGL loader! or smth");
            return false;
        }

        LogInfo("Successfully initialised OpenGL graphics context");
        return true;
    }

    void GLContext::SwapBuffers() {
        glfwSwapBuffers(mHandle);
    }

    void GLContext::Shutdown() {
        LogInfo("OpenGL graphics context shut down successfully");
    }

}