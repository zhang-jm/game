#version 330 core

in vec3 fragPos;
in vec3 vertNormal;
in vec4 vertColor;

out vec4 frag_color;

void main()
{
    vec3 lightPos = vec3(0.0f, 10.0f, 7.0f);

    vec3 norm = normalize(vertNormal);
    vec3 lightDir = normalize(lightPos - fragPos);

    // Diffuse shading
    float diff = max(dot(norm, lightDir), 0.0);

    vec4 diffuse = diff * vertColor;

    frag_color = diffuse;
}