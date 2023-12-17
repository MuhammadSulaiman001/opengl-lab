- Source code -> [Lesson32 at NeHe repo](https://github.com/gamedev-net/nehe-opengl/tree/master/vc/Lesson32)
- Project Properties (steps to get the code up and running):
	- C\C++ -> General -> Additional Include Directories = Relative path to .h files added
    	- .h files at the top of main.cpp can be found/downloaded from the repo
	- Linker -> General -> Additional Library Directories = Relative path to .libs files added
    	- The needed .lib files are the one mentioned in `#pragma lib(,)` calls in main.cpp
		- files were downloaded from the repo
    	- but, I've get winmm.lib from `C:\Program Files (x86)\Windows Kits\10`
	- Linker -> System -> SubSystem = "Windows"
	- Advanced -> Charachter Set = "Use Multi-Byte"
	- C/C++ -> Preprocessor -> preprocessor Definitions = _CRT_SECURE_NO_WARNINGS added
    - OutputPath/Temp Path Changed
    - Added Post build event to copy resources to output directory 

## Demo (Rebuild/Run)

![Demo](./../../res/demo.gif)