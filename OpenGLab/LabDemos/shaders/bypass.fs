#version 330 core
out vec4 FragColor;

in vec3 ourColor;

void main()
{
    // Check if ourColor is not set (all components are zero)
    if (ourColor == vec3(0.0f)) {
        // Set a default color (e.g., red)
        FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
    } else {
        // Use the provided ourColor value
        FragColor = vec4(ourColor, 1.0f);
    }
}