#pragma once

#include "CharCore.h"

#include <string>

namespace Charlotte {

    struct Matrix4;

    class CAPI Shader {
        public:
            virtual ~Shader() = default;

            static Ref<Shader> Create(const std::string& vertex, const std::string& fragment);

            virtual void Bind() = 0;
            virtual void Unbind() = 0;  

            virtual void SetUniformInt(const std::string& name, int value) = 0;
            virtual void SetUniformFloat(const std::string& name, float value) = 0;
            virtual void SetUniformFloat2(const std::string& name, float x, float y) = 0;
            virtual void SetUniformFloat3(const std::string& name, float x, float y, float z) = 0;
            virtual void SetUniformFloat4(const std::string& name, float x, float y, float z, float w) = 0;
            virtual void SetUniformMatrix4(const std::string& name, const Matrix4& value) = 0;
    };

}