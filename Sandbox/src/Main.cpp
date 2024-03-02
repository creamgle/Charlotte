#include "Charlotte/Core/Application.h"
#include "Charlotte/Core/Input.h"
#include "Charlotte/Core/Log.h"
#include "Charlotte/Core/Matrix4.h"
#include "Charlotte/Core/Transform.h"
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
                uniform mat4 uModel;
                uniform mat4 uProjection;
                void main() {
                    gl_Position = uProjection * uModel * vec4(aPosition, 1.0);
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
                { { 0, 0, 0 } },
                { { 1, 0, 0 } },
                { { 0, 1, 0 } },
                { { 1, 1, 0 } }
            };
            
            std::vector<uint32_t> triangles = {
                0, 1, 2,
                2, 3, 1
            };

            mShader = Shader::Create(vertex, fragment);
            mMesh = Mesh::Create(vertices, triangles);

            mTransform.Scale = (Vector3){ 100.0f, 100.0f, 1.0f };

            return true;
        }

        void Draw() override {
            BackendRenderer::SetClearColor(0.3, 0.3, 0.3, 1.0);
            BackendRenderer::Clear();

            Matrix4 projection = Matrix4::Ortho(0, GetWindow().GetWidth(), 0, GetWindow().GetHeight(), 0.0f, 100.0f);

            float speed = 1.0f;
            if (Input::GetKey(KeyCode::Left)) mTransform.Position.x -= speed;
            if (Input::GetKey(KeyCode::Right)) mTransform.Position.x += speed;

            if (Input::GetKey(KeyCode::Up)) mTransform.Position.y += speed;
            if (Input::GetKey(KeyCode::Down)) mTransform.Position.y -= speed;

            mShader->Bind();
            mShader->SetUniformMatrix4("uProjection", projection);
            mShader->SetUniformMatrix4("uModel", Transform::CreateModel(mTransform));
            mMesh->Draw();
            mShader->Unbind();
        }

    private:
        Ref<Mesh> mMesh;
        Ref<Shader> mShader;
        Transform mTransform;
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