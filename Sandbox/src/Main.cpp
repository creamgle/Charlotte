#include "Charlotte/Core/Application.h"
#include "Charlotte/Core/Log.h"
#include "Charlotte/Renderer/BackendRenderer.h"

using namespace Charlotte;

class SandboxApp : public Application {
    protected:
        bool Create() override {
            GetWindow().SetTitle("Boner pills are nothing but placebo");

            if (!BackendRenderer::Initialise()) {
                return false;
            }

            return true;
        }

        void Draw() override {
            BackendRenderer::SetClearColor(1, 0, 1, 1);
            BackendRenderer::Clear();
        }
};

int main() {
    ApplicationConfig config = { };
    config.Width = 1280;
    config.Height = 720;
    config.Title = "Sandbox - [Charlotte]";

    Application* app = new SandboxApp();
    
    if (!app->Run(config)) {
        LogFatal("Application did not shutdown gracefully!");
    }

    delete app;
}