#include "Application.h"
#include "Log.h"

namespace Charlotte {

    bool Application::Run(const ApplicationConfig& config) {
        mWindow = new Window(config.Width, config.Height, config.Title);
        if (!mWindow->Create()) {
            LogError("Failed to create platform window!");
            return false;
        }

        if (!Create()) {
            LogFatal("(Application)->Create() returned false! ABORTING...");
            return false;
        }

        while (!mWindow->ShouldExit()) {
            mWindow->PollEvents();
        }

        mWindow->Shutdown();
        delete mWindow;

        return true;
    }

}