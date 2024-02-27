#include "Charlotte/Core/Application.h"
#include "Charlotte/Core/Log.h"

class SandboxApp : public Charlotte::Application {
    protected:
        bool Create() override {
            LogFatal("This is a test %i", 10);
            LogError("This is a test %i", 10);
            LogWarn("This is a test %i", 10);
            LogInfo("This is a test %i", 10);
            LogDebug("This is a test %i", 10);

            return true;
        }
};

int main() {
    Charlotte::ApplicationConfig config = { };
    config.Width = 1280;
    config.Height = 720;
    config.Title = "Sandbox - [Charlotte]";

    Charlotte::Application* app = new SandboxApp();
    
    if (!app->Run(config)) {
        LogFatal("Application did not shutdown gracefully!");
    }

    delete app;
}