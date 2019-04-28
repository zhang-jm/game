#version 330 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec4 color;

out vec3 fragPos;
out vec3 vertNormal;
out vec4 vertColor;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    gl_Position = projection * view * model * vec4(position.x, position.y, position.z, 1.0);

    fragPos = vec3(model * vec4(position, 1.0));
    vertNormal = normal;
    vertColor = color;
}