#include <iostream>
#include <spdlog/spdlog.h>
#include <glm/vec3.hpp>

int main()
{
    std::cout << "Hello World!\n";
    spdlog::info("Welcome to spdlog!");
    auto vector3 = glm::vec3(.5, 1, 1);
    std::cout << "vector3.x = " << vector3.x;
}