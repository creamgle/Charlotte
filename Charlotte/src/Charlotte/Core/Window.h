#pragma once

#include "CharCore.h"
#include <string>

// TODO: Make it so glfw isnt required as this prevents mobile support
// (not that, that would happen anyways)
struct GLFWwindow;

namespace Charlotte {

    struct WindowData {
        std::string Title;
        uint32_t Width;
        uint32_t Height;

        WindowData(
            const std::string& title = "Made with Charlotte",
            uint32_t width = 1280,
            uint32_t height = 720
        ) : Title(title), Width(width), Height(height) { }
    };

    class CAPI Window {
        public:
            virtual ~Window() = default;

            static Scope<Window> CreateWindow(const WindowData& data = WindowData());

            virtual bool Create() = 0;
            virtual void PollEvents() = 0;
            virtual void SwapBuffers() = 0;
            virtual void Shutdown() = 0;
            virtual bool ShouldClose() = 0;

            virtual void SetSize(uint32_t width, uint32_t height) = 0;
            virtual void SetTitle(const std::string& title) = 0;

            virtual uint32_t GetWidth() const = 0;
            virtual uint32_t GetHeight() const = 0;
    };

}