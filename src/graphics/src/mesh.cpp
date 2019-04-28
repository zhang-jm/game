#include <graphics/incl/mesh.h>

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices)
    : vertices(std::move(vertices)),
    indices(std::move(indices)) {

    Setup();
}

Mesh::~Mesh() { }

void Mesh::Setup() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

    glBindVertexArray(0);
}

void Mesh::Render(const glm::mat4& model, const glm::mat4& view, const glm::mat4& proj, GLuint shader) {

    glUseProgram(shader);

    // Get the location of the uniform variables "projection" and "modelview"
    const GLuint uProjection = glGetUniformLocation(shader, "projection");
    const GLuint uView = glGetUniformLocation(shader, "view");
    const GLuint uModel = glGetUniformLocation(shader, "model");

    glUniformMatrix4fv(uModel, 1, GL_FALSE, &model[0][0]);
    glUniformMatrix4fv(uProjection, 1, GL_FALSE, &proj[0][0]);
    glUniformMatrix4fv(uView, 1, GL_FALSE, &view[0][0]);

    // draw mesh
    //if (cull_face)
        //glEnable(GL_CULL_FACE);
    //else
        //glDisable(GL_CULL_FACE);
    
    glEnable(GL_CULL_FACE);

    glCullFace(GL_BACK);
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glCullFace(GL_FRONT);
}