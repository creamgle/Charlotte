#include "macOS_Window.h"
#include "Charlotte/Core/Log.h"
#include "Charlotte/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Charlotte {

    macOS_Window::macOS_Window(const WindowData& data) : mData(data) { }
    macOS_Window::~macOS_Window() { }

    bool macOS_Window::Create() {
        if (!glfwInit()) {
            LogFatal("Failed to initialise GLFW!");
            return false;
        }

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_COCOA_RETINA_FRAMEBUFFER, GLFW_FALSE);

        mHandle = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);
        if (!mHandle) {
            LogFatal("Failed to create glfw window!");
            return false;
        }

        mContext = GraphicsContext::Create();
        mContext->Initialise(mHandle);

        return true;
    }

    void macOS_Window::PollEvents() {
        glfwPollEvents();
    }

    void macOS_Window::SwapBuffers() {
        mContext->SwapBuffers();
    }

    void macOS_Window::Shutdown() {
        mContext->Shutdown();
        glfwDestroyWindow(mHandle);
        glfwTerminate();
    }

    bool macOS_Window::ShouldClose() {
        return glfwWindowShouldClose(mHandle);
    }

    void macOS_Window::SetSize(uint32_t width, uint32_t height) {
        mData.Width = width;
        mData.Height = height;

        if (mHandle)
            glfwSetWindowSize(mHandle, width, height);
    }

    void macOS_Window::SetTitle(const std::string &title) {
        mData.Title = title;

        if (mHandle)
            glfwSetWindowTitle(mHandle, title.c_str());
    }

}