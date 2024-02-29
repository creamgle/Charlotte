#include "Charlotte/Core/Application.h"
#include "Charlotte/Core/Log.h"
#include "Charlotte/Renderer/BackendRenderer.h"
#include "Charlotte/Renderer/Mesh.h"
#include "Charlotte/Renderer/Shader.h"
#include <vector>

using namespace Charlotte;

class SandboxApp : public Application {
    protected:
        bool Create() override {
            GetWindow().SetTitle("Boner pills are nothing but placebo");

            if (!BackendRenderer::Initialise()) {
                return false;
            }

            const std::string& vertex = R"(
                #version 400
                layout(location=0) in vec3 aPosition;
                void main() {
                    gl_Position = vec4(aPosition, 1.0);
                }
            )";

            const std::string& fragment = R"(
                #version 400
                layout(location=0) out vec4 oFragColor;
                void main() {
                    oFragColor = vec4(1.0);
                }
            )";

            std::vector<Vertex> vertices = {
                { { -1, -1, 0 } },
                { { 1, -1, 0 } },
                { { 0, 1, 0 } }
            };
            
            std::vector<uint32_t> triangles = {
                0, 1, 2
            };

            mShader = Shader::Create(vertex, fragment);
            mMesh = Mesh::Create(vertices, triangles);

            return true;
        }

        void Draw() override {
            BackendRenderer::SetClearColor(1, 0, 1, 1);
            BackendRenderer::Clear();

            mShader->Bind();
            mMesh->Draw();
            mShader->Unbind();
        }

    private:
        Ref<Mesh> mMesh;
        Ref<Shader> mShader;
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