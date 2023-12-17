## Building spdlog (.lib + .h)

[spdlog](https://github.com/gabime/spdlog) is a Fast C++ logging library, let's build it and add it to a .vcxproj project.

Open Powershell 7.*

```
# cd to/opensource/folder!
# clone spdlog repo
git clone https://github.com/gabime/spdlog.git
# The headers can be found in "include" folder..
# create build directory and go there
cd spdlog && mkdir build && cd build
# let's generate the VS files (we're using vs2022 in this course, i.e. MSVC compiler)
cmake ..
# use msbuild to build the spdlog project (generate .lib file) (you should've added msbuild to your PATH, as explained in "Tech Tips.md" document)
msbuild spdlog.sln
# notice that Debug folder is created..
ls
# there should be a spdlogd.lib file inside Debug folder
ls .\Debug
# let's see its size!
(Get-Item .\Debug\spdlogd.lib).length/1MB
# more than 17 MB.. notice the 'd' before the extension in "spdlogd.lib".. it means "debug"..
# let's build the library in release mode!
msbuild .\spdlog.sln -p:configuration=release
# now, there is a new Release folder created
ls
# with spdlog.lib file inside it (no "d" before ".lib")
ls .\Release
# let's check the size
(Get-Item .\Release\spdlog.lib).length/1MB
# ~3 MB
# DONE.
```

Notice that we have built the library in command line (without opening visual studio).

Now that you've both the headers (.h files) and the .lib file, you can add those to your project as explained in "Tech Tips.md"