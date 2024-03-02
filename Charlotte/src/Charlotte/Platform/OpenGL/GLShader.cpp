#include "GLShader.h"

#include "Charlotte/Core/Log.h"
#include <glad/glad.h>

namespace Charlotte {

    GLShader::GLShader(const std::string& vertex, const std::string& fragment) {
        Generate(vertex, fragment);
    }

    GLShader::~GLShader() {
        glDeleteProgram(mProgram);
    }   

    void GLShader::Generate(const std::string& vertex, const std::string& fragment) {
        mProgram = glCreateProgram();

        uint32_t vShader = AddShader(GL_VERTEX_SHADER, vertex);
        uint32_t fShader = AddShader(GL_FRAGMENT_SHADER, fragment);

        glLinkProgram(mProgram);

        GLint isLinked = 0;
        glGetProgramiv(mProgram, GL_LINK_STATUS, &isLinked);
        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
			glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(mProgram, maxLength, &maxLength, &infoLog[0]);

            glDeleteShader(vShader);
            glDeleteShader(fShader);
            glDeleteProgram(mProgram);

            LogError(infoLog.data()); 
            LogError("Failed to link shader program");
        }

        glDetachShader(mProgram, vShader);
        glDetachShader(mProgram, fShader);
    }

    uint32_t GLShader::AddShader(uint32_t type, const std::string& source) {
        uint32_t shader = glCreateShader(type);

        const GLchar* sourceCStr = source.c_str();
        glShaderSource(shader, 1, &sourceCStr, 0);

        glCompileShader(shader);

        GLint isCompiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
        if (isCompiled == GL_FALSE) {
            GLint maxLength = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

            std::vector<GLchar> infoLog(maxLength);
            glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

            glDeleteShader(shader);

            std::string typeName = "UNKNOWN";
            if (type == GL_VERTEX_SHADER) typeName = "Vertex";
            else if (type == GL_FRAGMENT_SHADER) typeName = "Fragment";

            LogError(infoLog.data());
            LogError("Failed to compile %s shader!", typeName.c_str());
        }

        glAttachShader(mProgram, shader);

        return shader;
    }

    void GLShader::Bind() {
        glUseProgram(mProgram);
    }

    void GLShader::Unbind() {
        glUseProgram(0);
    }

    void GLShader::SetUniformInt(const std::string& name, int value) {
        glUniform1i(glGetUniformLocation(mProgram, name.c_str()), value);
    }

    void GLShader::SetUniformFloat(const std::string& name, float value) {
        glUniform1f(glGetUniformLocation(mProgram, name.c_str()), value);
    }

    void GLShader::SetUniformFloat2(const std::string& name, float x, float y) {
        glUniform2f(glGetUniformLocation(mProgram, name.c_str()), x, y);
    }

    void GLShader::SetUniformFloat3(const std::string &name, float x, float y, float z) {
        glUniform3f(glad_glGetUniformLocation(mProgram, name.c_str()), x, y, z);
    }

    void GLShader::SetUniformFloat4(const std::string& name, float x, float y, float z, float w) {
        glUniform4f(glGetUniformLocation(mProgram, name.c_str()), x, y, z, w);
    }

    void GLShader::SetUniformMatrix4(const std::string& name, const Matrix4& value) {
        glUniformMatrix4fv(glGetUniformLocation(mProgram, name.c_str()), 1, GL_FALSE, &value.m[0]);
    }

}