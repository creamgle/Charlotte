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
            Window(uint32_t width, uint32_t height, const std::string& title);
            ~Window();

            bool Create();
            void PollEvents();
            void Shutdown();
            bool ShouldExit();

        private:
            WindowData mData;
            GLFWwindow* mHandle;
    };

}