#pragma once

#include "Charlotte/Core/Window.h"
#include "Charlotte/Core/Log.h"

#include <GLFW/glfw3.h>

namespace Charlotte {

    Window::Window(uint32_t width, uint32_t height, const std::string& title) {
        mData = { };
        mData.Width = width;
        mData.Height = height;
        mData.Title = title;
    }

    Window::~Window() { }

    bool Window::Create() {
        if (mData.Width <= 0) {
            LogWarn("Window width of [%i] in invalid! setting to default value of [1280]", mData.Width);
            mData.Width = 1280;
        }

        if (mData.Height <= 0) {
            LogWarn("Window height of [%i] in invalid! setting to default value of [720]", mData.Height);
            mData.Height = 720;
        }

        if (!glfwInit()) {
            LogFatal("Failed to initialise GLFW!");
            return false;
        }

        glfwDefaultWindowHints();

        mHandle = glfwCreateWindow(mData.Width, mData.Height, mData.Title.c_str(), nullptr, nullptr);
        if (!mHandle) {
            LogFatal("Failed to create GLFW window!");
            return false;
        }

        return true;
    }

    void Window::PollEvents() {
        glfwPollEvents();
    }

    void Window::Shutdown() {
        glfwDestroyWindow(mHandle);
        glfwTerminate();
    }

    bool Window::ShouldExit() {
        return glfwWindowShouldClose(mHandle);
    }

}