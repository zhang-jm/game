#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>

// GL Includes
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Mesh;
class ShaderLoader;

class Model {
public:
	Model(ShaderLoader& loader, const char* path, const char* vertex_shader, const char* frag_shader);
	~Model();

    void Render(const glm::mat4& view, const glm::mat4& projection);

private:
    GLuint shader;

    std::vector<Mesh> meshes;

    void LoadModel(const std::string path);
    void ProcessNode(aiNode* node, const aiScene* scene);
    Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);

};

#endif