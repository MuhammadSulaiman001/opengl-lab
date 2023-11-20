#version 460 core
out vec4 FragColor;

in vec3 ourColor;

void main()
{
    // Use the provided ourColor value
    FragColor = vec4(ourColor, 1.0f);
}