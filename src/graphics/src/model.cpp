#include <graphics/incl/model.h>
#include <graphics/incl/mesh.h>
#include <graphics/incl/shader_loader.h>

Model::Model(ShaderLoader& loader, const char* path, 
    const char* vertex_shader_path, const char* frag_shader_path) {
    
    LoadModel(path);
    shader = loader.LoadShader(vertex_shader_path, frag_shader_path);
}

Model::~Model() {

}

void Model::Render(const glm::mat4& view, const glm::mat4& projection) {
    for (auto mesh : meshes) {
        //TODO: get actual model matrix lol
        mesh.Render(glm::scale(glm::mat4(1.0f), glm::vec3(2.0f, 2.0f, 2.0f)) , view, projection, shader);
    }
}

void Model::LoadModel(const std::string path) {
    std::cout << "Loading model at path: " << path << std::endl;

    // read file via ASSIMP
    Assimp::Importer importer;
    const aiScene* const scene = importer.ReadFile(path, aiProcess_Triangulate);

    // check for errors
    if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "Error: Assimp could not load model -  " << importer.GetErrorString() << std::endl;
        return;
    }

    // process root node recursively
    ProcessNode(scene->mRootNode, scene);
}

void Model::ProcessNode(aiNode* node, const aiScene* scene) {

    // parse meshes for current node
    for (GLuint i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* const mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(ProcessMesh(mesh, scene));
    }

    // recursively parse children nodes
    for (GLuint i = 0; i < node->mNumChildren; i++)
    {
        ProcessNode(node->mChildren[i], scene);
    }
}

Mesh Model::ProcessMesh(aiMesh* mesh, const aiScene* scene) {

    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;

    // parse vertices for mesh
    for (GLuint i = 0; i < mesh->mNumVertices; i++)
    {
        std::cout << "parse mesh" << std::endl;

        Vertex vertex;
        vertex.position.x = mesh->mVertices[i].x;
        vertex.position.y = mesh->mVertices[i].y;
        vertex.position.z = mesh->mVertices[i].z;

        // normals
        if (mesh->mNormals == NULL)
        {
            vertex.normal = glm::vec3(0.0f);
        }
        else
        {
            vertex.normal.x = mesh->mNormals[i].x;
            vertex.normal.y = mesh->mNormals[i].y;
            vertex.normal.z = mesh->mNormals[i].z;
        }

        // process materials
        if (mesh->mMaterialIndex >= 0)
        {
            aiMaterial* const material = scene->mMaterials[mesh->mMaterialIndex];
            std::cout << "not diffuse" << std::endl;
            vertex.color = glm::vec4(1.0f);

            aiColor4D diffuse;
            if (AI_SUCCESS == aiGetMaterialColor(material, AI_MATKEY_COLOR_DIFFUSE, &diffuse))
            {
                std::cout << "diffuse" << std::endl;
                vertex.color = glm::vec4(diffuse.r, diffuse.g, diffuse.b, diffuse.a);
            }
        }

        vertices.push_back(vertex);
    }

    // get indices for vertexes
    for (GLuint i = 0; i < mesh->mNumFaces; i++)
    {
        const aiFace& face = mesh->mFaces[i];

        for (GLuint j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    return Mesh(vertices, indices);
}
