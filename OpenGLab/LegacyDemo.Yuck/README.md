- Source code -> [Lesson32 at NeHe repo](https://github.com/gamedev-net/nehe-opengl/tree/master/vc/Lesson32)
	- with minor code edits (const_cast<char*>(), (byte)bits cast)
- Project Properties (done):
	- C\C++ -> General -> Additional Include Directories = Relative path to .h files added
	- Linker -> General -> Additional Library Directories = Relative path to .libs files added
	- Linker -> Input -> Additional Dependencies = .libs files' names added
	- Linker -> System -> SubSystem = "Windows"
	- Advanced -> Charachter Set = "Use Multi-Byte"
	- C/C++ -> Preprocessor -> preprocessor Definitions = _CRT_SECURE_NO_WARNINGS added
    - OutputPath/Temp Path Changed
    - Post build event to copy DATA added
- Note: x64 configuration removed, as .lib is built under x86 configuration

## Demo (Rebuild/Run)

![Demo](res/demo.gif)