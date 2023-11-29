## Good-To-Have Tools
- Install/Upgrade Terminal [(From Microsoft Store)](https://apps.microsoft.com/detail/windows-terminal/9N0DX20HK701?hl=en-US)
    - Configure the *settings* to: 
        - Make "Terminal" the default terminal in windows,
        - Make powershell 7.3.x the default terminal, 
        - Run as administrator, 
        - Run at startup.
- Install/Upgrade `make` using [choco](https://www.gnu.org/software/make/), 
    - Open Powershell 7,
    - `choco upgrade chocolatey` # optional
    - `choco upgrade all` # optional
    - `choco list` # see all packages installed by choco
    - **`choco install make` # install make**
    - `choco upgrade make` # upgrade make
- **We won't use [vcpkg](https://vcpkg.io/)** during this course.

## `.vcxproj` setup (best practices)

When creating new project in Visual Studio, configure project properties -> General, like the following:

- Select "All configurations" and "All platforms" for top dropdowns,
- C++ Language Standard = C++ 20
- Output/Temp Directories:
    - The default location is at **.sln level**, so all projects will dump their output in one place! I don't like this, Let's isolate the build output for each project to be at **.cxproj level**
    - Output Directory: `$(ProjectDir)$(Platform)\$(Configuration)`
    - Temp Directory: `$(ProjectDir)$(Platform)\$(Configuration)\Temp`
    
## Coding

- Don't just put .cpp, .h, etc.. files at project root, keep things organized as much as possible (check projects in this repo as an example),
- Clean code principles and best practices:
    - DRY
    - KISS
    - SOLID
    - YAGNI
    - etc...

## Package manager

- We won't use [vcpkg](https://vcpkg.io/) during this course, in order to make sure all dependencies are bundled within the project(s) (under git supervision),
- Anyway, triggering package managers (like vcpkg) to install project dependencies on any machine is possible, but out of the scope of this course.

## Consuming libraries

Libaries can be found in different flavors, the common ones are:
- Headers only (ex. glm)
- Headers and sources (ex. glad, stb)
- Headers + Lib (ex. glfw)
- Headers + Lib + DLL (ex. assimp, irrklang, glut)

1. To tell VS where the header files are (so you can `#include <>` them):
    - Project properties -> C\C++ -> General -> Additional Include Directories, 
    - add a **relative path** to where these header files are.
2. To tell VS where the implementation binaries are:
    - Project properties -> Linker -> General -> Additional Library Directories, 
    - add a **relative path** to .lib files
3. Tell the linker what libs you want to consume by adding their names in:
    - Code, via `#pragma comment(lib, "lib-name.lib")` 
    - Or: from Project properties -> Linker -> Input -> Additional Dependencies
4. To consume sources (c/c++ files), just add them to your project:
    - Move the source files to the project -> Solution Explorer -> Show Hidden Files -> Right click on the newly added source files -> Include In Project.
5. To Consume dll files:
    - Project properties -> Build Events -> Post-Build-Event
    - Trigger powershell to execute a .ps1 script that copies the dlls to output directory (recommended)
        - Check `LabDemos` project to see an example
    - Or: add `xcopy` command to copy the dlls to output directory
        - Check `LegacyDemo.Yuck` project to see an example

### So, If you want to install a library that is shared between many projects (ex. spdlog, glm, etc...), where to put these files?

- Visual studio searchs for .h and .dll files in many places, for example, in all PATH paths, so some developers put such files outside their projects!
    - Don't do that!
    - `git` should track all resources and dependencies,

- Create *dependencies* folder
    - For example, at .sln level (i.e. where .sln file exist), so it is under git supervision, and outside all projects,
    - In this course, I've create many applications, so I've created a shared module (a library, `OpenGL.SharedModule`) to put implementation units (ex. glad.c, imgui*.cpp, etc...) files in it, therefore, I've decided to put *dependencies* inside this shared module.
    - Create like  dlls, libs, include folders inside it, and put shared files in the appropriate folders,

- NOTE: It's unlikely that projects share the same resources (ex. textures, audio files, etc...), therefore, such files will be in *resources* folder, inside the project folder


## Build output

- App should run via .exe double click, on any machine!
    - Use Post-Build-Event to copy the needed resources (ex. images, shaders, dlls, etc...) to build output directory,
    - Recommended: let the event call .ps1 script, which will run one/more commands.
    - [Optional]: Use packaging projects like NSIS, InnoSetup, etc... to create .exe/.msi installers.

### VS Extensions 

These are some extensions to install in Visual Studio
- Markdown Editor v2: preview markdown documents in a side panel
- VSColorOutput64: colors the output in output panel

## Unit-Testing

- VS comes with 2 types of test projects: Native Unit Test project (using Microsoft CppUnitTest framework), and Google Test project (using [GoogleTest](https://github.com/google/googletest) library), You can run unit tests in Visual Studio:
- To run the tests: VS -> Test -> Test Explorer, wait until test explorer loads and detects the unit tests -> run the tests using: 1. run button, 2. righ click on project/file/function and select "Run Tests" from the menu
- Because test project can reference a library (i.e. .lib)  but can't reference an application (i.e. .exe), it'll be challenging to create a unit test for a function inside an application, this is how you can manage to overcome such an issue,
    - First, when compiling an .exe application, .cpp files are converterd to .obj files, then .obj files are linked in an .exe file,
    - In test project properties, we'll tell the linker to link the .obj (where the implementation for functions in .h files is) file when building the test project..
        - Properties -> Linker -> General = add path for file-name.obj parent,
        - Properties -> Linker -> Input = add file-name.obj
        - **Refer to `UnitTests` project to see an example of how I've tested `DxfParser` methods that are declared and defined in `Homework.OpenGlDxfViewer` application**

### Install assimp (manually)

- Check prebuild-binaries at [assimp repo](https://github.com/assimp/assimp)
    - Itchi Projectspace
- Download x64 exe, install it (note the installation location)
- Go to installation location, 
    - .h files in include folder
    - .lib file in lib\x64
    - .dll file in bin\x64
- [assimp models database](https://github.com/assimp/assimp-mdb)

### Misc. Tips

- In solution explorer, select the project you're working on, toggle ON "Show all files", this will show the actual folders on desk, rather than solution filters, so you can organize the files better!
- While developing, be aware configs are set to Debug, not Release
- When creating new project in Visual Studio, don't create the project and the solution at the same level (there is a checkbox that asks you if you want to do that!)
- If there is, for some reasone, more than one entry point in the application (ex. 2 cpp files, each has a main function), then you must exclude one file from build..
    - File properties -> exclude from build = Yes
- To run project without set it as startup: Right click -> debug -> run instance.
- Rebuild the project after writing code in shader's file..
- > Access violation executing location ...
    - common crash
    - check if `gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);` missing!
- 3d model-loading speed can be enhanced in release Configuration.
- In Visual Studio, when the build fails with a huge stacktrace, you can check the name of the .cpp file that is mentioned just before the first error.. That would be the file that causes the build to fail!
- In visual studio, you can exclude .cpp file from the build by right click -> properties -> exclude from build = Yes.
- 