#include "GLApi.h"

#include <glad/glad.h>

namespace Charlotte {

    bool GLApi::Initialise() {
        return true;
    }

    void GLApi::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        glViewport(x, y, width, height);
    }

    void GLApi::SetClearColor(float r, float g, float b, float a) {
        glClearColor(r, g, b, a);
    }

    void GLApi::Clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    }

}