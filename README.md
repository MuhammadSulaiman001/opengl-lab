# OpenGL-Lab (2023-2024)

## Start Quickly

1. Install/Update [Visual studio 2022 - Community Edition](https://visualstudio.microsoft.com/downloads/)

![vs2022-installer-workloads](./res/vs2022-installer-workloads.png)

2. Install/Update CMake [(official site)](https://cmake.org/download/) (use the `.msi`)
3. Install/Update Git [(official site)](https://git-scm.com/downloads)
4. Install/Update Powershell [(Microsoft Store)](https://apps.microsoft.com/store/detail/powershell/9MZ1SNWT0N5D)
5. Add CMake and Git to PATH environmental variable (at top of the list), these are the default paths
    * `C:\Program Files\CMake\bin`
    * `C:\Program Files\Git\bin`
6. Run the following commands in Powershell (one by one)

```
cmake --version # verify cmake is installed
git --version # verify git is installed
# cd path\where\you\clone\opensource\projects
git clone https://github.com/JoeyDeVries/LearnOpenGL
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

1. [Learn C++](https://learn.microsoft.com/en-us/cpp/cpp/?view=msvc-170) and [Visual Studio for C++]([https://learn.microsoft.com/en-us/cpp/get-started/tutorial-console-cpp?view=msvc-170](https://learn.microsoft.com/en-us/cpp/build/projects-and-build-systems-cpp?view=msvc-170))
   * GitHub repos: [CPP_Beginner_to_Expert](https://github.com/tridibsamanta/CPP_Beginner_to_Expert), [cpluspluscourse](https://github.com/hsf-training/cpluspluscourse) and [Cpp-Tutorial-Samples](https://github.com/sinairv/Cpp-Tutorial-Samples)
2. [Learn OpenGL](https://learnopengl.com/Introduction).
3. Learn the basics of Git and Powershell.
