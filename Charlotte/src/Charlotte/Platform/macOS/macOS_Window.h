#pragma once

#include "CharCore.h"
#include "Charlotte/Core/Window.h"
#include "Charlotte/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Charlotte {

    class CAPI macOS_Window : public Window {
        public:
            macOS_Window(const WindowData& data);
            ~macOS_Window() override;

            bool Create() override;
            void PollEvents() override;
            void SwapBuffers() override;
            void Shutdown() override;
            bool ShouldClose() override;

            void SetSize(uint32_t width, uint32_t height) override;
            void SetTitle(const std::string& title) override;

            uint32_t GetWidth() const override { return mData.Width; }
            uint32_t GetHeight() const override { return mData.Height ; }

        private:
            WindowData mData;
            GLFWwindow* mHandle;

            Scope<GraphicsContext> mContext;
    };

}