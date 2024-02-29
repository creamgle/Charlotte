#include "GLMesh.h"
#include "Charlotte/Core/Log.h"
#include "Charlotte/Renderer/Mesh.h"

#include <glad/glad.h>
#include <vector>

namespace Charlotte {

    GLMesh::GLMesh(std::vector<Vertex> vertices, std::vector<uint32_t> triangles) 
        : mVertices(vertices), mTriangles(triangles) {
        Generate();
    }

    GLMesh::~GLMesh() {
        glDeleteVertexArrays(1, &mVao);
    }

    void GLMesh::Generate() {
        uint32_t vbo, ebo;


        glGenVertexArrays(1, &mVao);
        glBindVertexArray(mVao);

        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), &mVertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mTriangles.size() * sizeof(uint32_t), &mTriangles[0], GL_STATIC_DRAW);

        /* Position Attribute */
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));

        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        LogInfo("Successfully loaded mesh [vertex_count: %i, tri_count: %i]", mVertices.size(), mTriangles.size());
    }

    void GLMesh::Draw() {
        glBindVertexArray(mVao);
        glDrawElements(GL_TRIANGLES, mTriangles.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

}