#include "Application.h"
#include "Charlotte/Core/Window.h"
#include "Log.h"

namespace Charlotte {

    bool Application::Run(const ApplicationConfig& config) {
        WindowData data = { };
        data.Width = config.Width;
        data.Height = config.Height;
        data.Title = config.Title;

        mWindow = Window::CreateWindow(data);
        if (!mWindow->Create()) {
            LogError("Failed to create platform window!");
            return false;
        }

        if (!Create()) {
            LogFatal("(Application)->Create() returned false! ABORTING...");
            return false;
        }

        while (!mWindow->ShouldClose()) {
            Update();
            
            Draw();

            mWindow->SwapBuffers();
            mWindow->PollEvents();
        }

        mWindow->Shutdown();
        return true;
    }

}