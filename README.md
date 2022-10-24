# prolog-lab 

2022-2023

## Notes:

1. There will be a ***separate branch for each lecture***
2. **Useful [git](https://git-scm.com/download/win) commands**
    1. Clone this repo: `git clone https://github.com/MuhammadSulaiman001/opengl-lab.git`
    2. List all available branches: `git branch -a`
    3. Checkout {branch-name} branch: `git checkout {branch-name}`
3. Don't hesitate to start a [disscussion](https://github.com/MuhammadSulaiman001/opengl-lab/discussions), open an issue and create pull requests..

## Environmental Setup

Files can be found in [this folder](/setup%20files/)..

1. Copy the content from "setup files\header files" to "VC\Auxiliary\VS\include", example paths:
	- C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\include
	- C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\VS\include

2. Copy the content from "setup files\libs" to "VC\Auxiliary\VS\lib\x86", example paths:
	- C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\lib\x86
	- C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\VS\lib\x86

	2.1. Copy the files that does not end with "32" to x64 folder.

3. Copy the content from "setup files\dlls" to "C:\Windows\System32"

## Configure Visual Studio<sup>[1]</sup>

- Project Properties -> Linker -> Input 
		-> Additional Dependencies 
		-> Edit -> past: **GLAUX.lib;GLU32.lib;glut.lib;OPENGL32.lib;glut32.lib**
		-> Ok -> Apply

- Project Properties -> Linker -> System -> SubSystem = Windows -> Ok -> Apply

- Project Properties -> Advanced 
-> Charechter set = "Use multi-byte character set"

- Project Properties -> Configuration Manager -> 
Active Solution Platform = x86, Platform = Win32, Check Build.

---
<sup>[1]</sup> You can use whatever version you want! Personally, I use Visual Studio 2022
