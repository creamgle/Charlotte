#pragma once

#include "CharCore.h"
#include "Charlotte/Renderer/Shader.h"

#include <string>

namespace Charlotte {

    class CAPI GLShader : public Shader {
        public:
            GLShader(const std::string& vertex, const std::string& fragment);
            ~GLShader() override;

            void Bind() override;
            void Unbind() override;

            void SetUniformInt(const std::string& name, int value) override;
            void SetUniformFloat(const std::string& name, float value) override;
            void SetUniformFloat2(const std::string& name, float x, float y) override;
            void SetUniformFloat3(const std::string& name, float x, float y, float z) override;
            void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) override;

        private:
            void Generate(const std::string& vertex, const std::string& fragment);
            uint32_t AddShader(uint32_t type, const std::string& source);

            uint32_t mProgram;
    };

}