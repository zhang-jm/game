#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex{
	glm::vec3 position;
	glm::vec3 normal;
    glm::vec4 color;
};

class Mesh {
public:
	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
	~Mesh();

	void Render(const glm::mat4& model, const glm::mat4& view, const glm::mat4& proj, GLuint shader);

private:
    void Setup();

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;

	unsigned int VAO, VBO, EBO;
};

#endif