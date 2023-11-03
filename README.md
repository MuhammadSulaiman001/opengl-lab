# OpenGL-Lab (2023-2024)

## Quick Start

- Please note that the following configuration is not opengl-specific, but is for almost any C++ project out there!

1. Install/Update [Visual studio 2022 - Community Edition](https://visualstudio.microsoft.com/downloads/)

![vs2022-installer-workloads](./res/vs2022-installer-workloads.png)

2. Install/Update CMake [(official site)](https://cmake.org/download/) (use the `.msi`)
3. Install/Update Git [(official site)](https://git-scm.com/downloads)
4. Install/Update Powershell [(Microsoft Store)](https://apps.microsoft.com/store/detail/powershell/9MZ1SNWT0N5D)
    - Or from [GitHub repo](https://github.com/PowerShell/PowerShell/releases)
    - Needs VPN (in some countries 🤔)
5. Add CMake and Git to PATH environmental variable (at top of the list), these are the default paths
    * `C:\Program Files\CMake\bin`
    * `C:\Program Files\Git\bin`
6. Run the following commands in Powershell (one by one)

```
cmake --version # verify cmake is installed
git --version # verify git is installed
# cd path\where\you\clone\opensource\projects
git clone https://github.com/JoeyDeVries/LearnOpenGL
cd LearnOpenGL
mkdir build && cd build # create/move to build directory
cmake .. # build the build system :)
# cmake --build . # build all the projects, might take few minutes!
cmake --build . --target 1.getting_started__2.1.hello_triangle # builds only this target
cd ..\bin\1.getting_started\Debug # move to output location
.\1.getting_started__2.1.hello_triangle.exe # run the exe you've built
# explorer.exe . # open in windows explorer!
```

Now, you have built the sample and run it, without writing any C++ code or opening visual studio at all.

---

## Next:

1. [Get familiar with the build system and the IDE](https://learn.microsoft.com/en-us/cpp/build/projects-and-build-systems-cpp?view=msvc-170)
2. [Learn C++](https://learn.microsoft.com/en-us/cpp/cpp/?view=msvc-170)
2. [Learn OpenGL](https://learnopengl.com/Introduction)
3. Learn the basics of Git, Poweshell 7.x.x and CMake
    - [Getting started with git](https://git-scm.com/book/en/v2)/[cheatsheet](https://training.github.com/downloads/github-git-cheat-sheet/)
    - [Getting started with Powershell](https://learn.microsoft.com/en-us/powershell/scripting/learn/ps101/01-getting-started?view=powershell-7.3)
    - [Getting started with CMake](https://cmake.org/cmake/help/latest/guide/tutorial/A%20Basic%20Starting%20Point.html)

## Lectures' Reference
- Articles on [learnopengl.com](https://www.learnopengl.com) are the main reference for this Lab.
    - **Mainly:** Getting started, Lightining, Model Loading, Depth Testing and Blending.
    - Complementary: the remaining topics!

## Good-To-Have Tools:
- Install/Upgrade Terminal [(From Microsoft Store)](https://apps.microsoft.com/detail/windows-terminal/9N0DX20HK701?hl=en-US)
    - Configure the settings to: 
        - Make powershell 7.3.x the default terminal, 
        - Run as adminstrator 
        - Run at startup.
- Install/Upgrade Make using [Powershell/Choco](https://www.gnu.org/software/make/)
    - `choco upgrade chocolatey` # optional
    - `choco upgrade all` # optional
    - `choco list` # see all packages installed by choco
    - **`choco install make` # install make**
    - `choco upgrade make` # upgrade make
- **We won't use [vcpkg](https://vcpkg.io/)** during this course.

## Awesome OpenGL Games:
- [AntWar](https://github.com/YamanQD/AntWare/): Damascus university project 2021-2022
- [AntiAnts](https://github.com/HasanMothaffar/AntiAnts): Damascus university project 2021-2022
- [Pepsico-man](https://github.com/Abd-ELrahmanHamza/Pepsico-man): University project
- [Super mario](https://github.com/Deathmajorasmask/MarioRPG-OpenGL)
- [SolarSystem-3D](https://github.com/GTruf/SolarSystem-3D): just a scene!
- [More](https://github.com/topics/game?l=c%2B%2B) and [more...](https://github.com/topics/opengl?l=c%2B%2B)
    - I'll update this list over and over, there are tons of games on GitHub out there, just wanna mention the good/lovely ones.

## Awesome OpenGL dependencies:
- [glfw](https://github.com/glfw/glfw): Create game window and get user input
- [glad](https://github.com/Dav1dde/glad): OpenGL loader
    - alternative: [glew](https://github.com/nigels-com/glew)
- [stb](https://github.com/nothings/stb/): image loader, etc...
- [glm](https://github.com/g-truc/glm): math library
- [nanogui](https://github.com/wjakob/nanogui): add controls (buttons/dropdowns/etc..) to glfw window
    - alternative [imgui](https://github.com/ocornut/imgui/)
- [bullet3](https://github.com/bulletphysics/bullet3): physics simulation and collision detection
- [assimp](https://github.com/assimp/assimp)
- [irrklang](https://www.ambiera.com/irrklang/)/[Getting Started](https://www.ambiera.com/irrklang/tutorial-helloworld.html)

## Awesome OpenGL tutorials:
- **[LearnOpenGL](https://github.com/JoeyDeVries/LearnOpenGL)**
- [ogl](https://github.com/opengl-tutorials/ogl)
- [opengl-tutorials](https://github.com/VictorGordan/opengl-tutorials)
- [ogldev](https://github.com/emeiri/ogldev)
- [Learn-OpenGL](https://github.com/PacktPublishing/Learn-OpenGL): by Packt
- [OpenGL-3D-Game-Tutorial-Series](https://github.com/PardCode/OpenGL-3D-Game-Tutorial-Series)
- ~~[deprecated][nehe-opengl](https://github.com/gamedev-net/nehe-opengl): legacy OpenGL~~
- ~~[deprecated][opengl-demos](https://github.com/Dovyski/opengl-demos/): legacy OpenGL~~

## Other OpenGL Awesomes!
- [OpenGL-Renderer](https://github.com/htmlboss/OpenGL-Renderer)
- [raylib](https://github.com/raysan5/raylib)
- [Glitter](https://github.com/Polytonic/Glitter): OpenGL project template with common dependencies.
- [More...](https://github.com/eug/awesome-opengl)

## Awesome C++ tutorials
- [modern-cpp-tutorial](https://github.com/changkun/modern-cpp-tutorial)
- [CPP_Beginner_to_Expert](https://github.com/tridibsamanta/CPP_Beginner_to_Expert)
- [cpluspluscourse](https://github.com/hsf-training/cpluspluscourse)
- [Cpp-Tutorial-Samples](https://github.com/sinairv/Cpp-Tutorial-Samples) 

## Awesome C++ libraries
- [spdlog](https://github.com/gabime/spdlog): Fast C++ logging library
- [json](https://github.com/nlohmann/json)
- [SFML](https://github.com/SFML/SFML)
- [nsis](https://github.com/kichik/nsis): Create windows installer for your app
- [libnest2d](https://github.com/tamasmeszaros/libnest2d)
- [More...](https://github.com/fffaraz/awesome-cpp)

## Awesome C++ applications (wanna see real-life projects?)
- [Notepad++](https://github.com/notepad-plus-plus/notepad-plus-plus): World-Wide Text editor
- [Windows Calculater Application](https://github.com/microsoft/calculator/)
- [LibreCAD](https://github.com/LibreCAD/LibreCAD): World-Wide CAD editor
- [Qt](https://github.com/qt/qtbase/tree/dev)
- [opencv](https://github.com/opencv/opencv): World-Wide Image processing library
- [tesseract](https://github.com/tesseract-ocr/tesseract): World-Wide OCR library

## vcxproj setup (best practices):
- In general: change project settings for all configurations (debug/release) and all platforms (x86, x64).
- Change Output/Temp directories to be created inside the project directory, for example:
    - Output Directory: `$(ProjectDir)$(Platform)\$(Configuration)`
    - Temp Directory: `$(ProjectDir)$(Platform)\$(Configuration)\Temp`
- Create `dependencies` directory at root directory (next to .sln file) to be shared for all projects
    - Create dlls/libs/headers folders inside it
- Don't use vcpkg (unless if your developing using CMake)
- Use Post-Build-Event to copy dll files and all other resources (ex. images/shaders/etc...) to output directory
    - Recommended: let the event call .ps1 script, which will run one/more commands.
    - Your app should run via .exe double click!
- Let the application encapsulates all needed resources in order to build it successfully on other machines
    - Don't put .lib files, .h/.hpp files and .dll files in common directories (outside your solution).. git should track these files.
- Don't just list .cpp/.h/etc.. files at project directory..
    - create src/headers/resources/scripts/shaders/etc.. directories, so you keep things organized as much as possible!


## Consuming libraries

Libaries can be found in different flavors, the common ones are:
- Headers only (ex. glm)
- Headers and sources (ex. glad, stb)
- Headers + Lib (ex. glfw)
- Headers + Lib + DLL (ex. assimp)

1. To tell VS where the header files are (so you can `#include <>` them), go to:
    - Project properties -> C\C++ -> General -> Additional Include Directories, 
    - add a **relative path** to where these header files are.
2. To tell VS where the implementation binaries are, go to:
    - Project properties -> Linker -> General -> Additional Library Directories, 
    - add a relative path to .libs files
3. Tell the linker what libs you want to consume by adding their names in:
    - Code, via `#pragma comment(lib, "lib-name.lib")` 
    - Or: from Project properties -> Linker -> Input -> Additional Dependencies
4. For sources (c/c++ files), just add them to your project
    - Move the source files to the project -> Solution Explorer -> Show Hidden Files -> Right click on the newly added source files -> Include In Project.
5. For dll files, go to:
    - Project properties -> Build Events -> Post-Build-Event
    - Trigger powershell to execute a .ps1 script that copyies the dlls to output directory (recommended)
        - Check `LabDemos` project to see an example
    - Or: add `xcopy` command to copy the dlls to output directory
        - Check `LegacyDemo.Yuck` project to see an example
