#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#include <vector>
#include <map>


typedef std::vector<std::pair<unsigned int, const char*>> Shader;

class ShaderLoader {
public:
    ShaderLoader();
	~ShaderLoader();

    int LoadShader(const char * vertexShaderPath, const char * fragmentShaderPath);
    int LoadShader(const char * vertexShaderPath, const char * fragmentShaderPath, const char * geometryShaderPath);

private:
    std::map<Shader, unsigned int> shaderCache;

    int ParseShader(const Shader& s);
};

#endif