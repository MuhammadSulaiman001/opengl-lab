- Source code -> [Lesson32 at NeHe repo](https://github.com/gamedev-net/nehe-opengl/tree/master/vc/Lesson32)
	- with minor code edits (const_cast<char*>(), (byte)bits cast)
- Project Properties (done):
	- C\C++ -> General -> Additional Include Directories = Relative path to .h files added
    	- .h files at the top of main.cpp can be downloaded from the repo
	- Linker -> General -> Additional Library Directories = Relative path to .libs files added
    	- The needed .lib files are the one mentioned in `#pragma lib(,)` calls in main.cpp
		- files downloaded from the repo
    	- but I've get winmm.lib from `C:\Program Files (x86)\Windows Kits\10`
	- Linker -> System -> SubSystem = "Windows"
	- Advanced -> Charachter Set = "Use Multi-Byte"
	- C/C++ -> Preprocessor -> preprocessor Definitions = _CRT_SECURE_NO_WARNINGS added
    - OutputPath/Temp Path Changed
    - Post build event to copy resources added
- Note: x64 configuration removed, as .lib is built under x86 configuration

## Demo (Rebuild/Run)

![Demo](./../../res/demo.gif)