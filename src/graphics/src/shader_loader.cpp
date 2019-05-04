#include <glad/glad.h>
#include <graphics/incl/shader_loader.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

ShaderLoader::ShaderLoader() {

}

ShaderLoader::~ShaderLoader() { }

int ShaderLoader::LoadShader(const char * vertexShaderPath, const char * fragmentShaderPath) {

    Shader s;
    s.reserve(2);
    s.emplace_back(GL_VERTEX_SHADER, vertexShaderPath);
    s.emplace_back(GL_FRAGMENT_SHADER, fragmentShaderPath);

    // save shader if successful load
    int programID = this->ParseShader(s);
    if (programID >= 0) {
        shaderCache.emplace(s, programID);
    }

    return programID;
}

int ShaderLoader::LoadShader(const char * vertexShaderPath, const char * fragmentShaderPath, 
                             const char * geometryShaderPath) {

    Shader s;
    s.reserve(3);
    s.emplace_back(GL_VERTEX_SHADER, vertexShaderPath);
    s.emplace_back(GL_FRAGMENT_SHADER, fragmentShaderPath);
    s.emplace_back(GL_GEOMETRY_SHADER, geometryShaderPath);
    
    // save shader if successful load
    int programID = this->ParseShader(s);
    if (programID >= 0) {
        shaderCache.emplace(s, programID);
    }

    return programID;
}

int ShaderLoader::ParseShader(const Shader& s) {

    if (shaderCache.count(s) > 0) {
        std::cout << "Shader already loaded!" << std::endl;
        
        return shaderCache.at(s);
    }

    const GLuint program = glCreateProgram();

    GLint success;
    GLchar infoLog[1024];
    for (auto shaderfile : s) {

        if (shaderfile.second == nullptr)
            continue;

        std::string shaderFileCodeString;
        std::ifstream shaderFileCodeStream;
        shaderFileCodeStream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

        try
        {
            // open file
            std::cout << shaderfile.second << std::endl;
            shaderFileCodeStream.open(shaderfile.second); 

            // read file contents into stream
            std::stringstream shaderStream;
            shaderStream << shaderFileCodeStream.rdbuf();

            // close file handler
            shaderFileCodeStream.close();

            // save string
            shaderFileCodeString = shaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "Error: could not read file " << shaderfile.second << " - " << e.what() << std::endl;
            return -1;
        }

        const char * shaderFileCode = shaderFileCodeString.c_str();
        // compile shader
        GLuint shader = glCreateShader(shaderfile.first);
        glShaderSource(shader, 1, &shaderFileCode, NULL);
        glCompileShader(shader);
        
        //check shader compile errors
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
                glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "Error: shader compilation error - " << infoLog << std::endl;
                return -1;
        }

        // attach shader
        glAttachShader(program, shader);
        glDeleteShader(shader);
    }

    // link program & check errors
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(program, 1024, NULL, infoLog);
        std::cout << "Error: program link error - " << infoLog << std::endl;
        return -1;
    }

    return program;
}
