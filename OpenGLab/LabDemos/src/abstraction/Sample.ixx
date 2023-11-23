module; // optional. Defines the beginning of the global module fragment

// #include directives go here but only apply to this file.
// import statements aren't allowed here. They go in the module preamble, below.

export module Sample;

/*
Q: Why export namespaces?
A: This will make it easy for me to just copy/paste the code from https://github.com/JoeyDeVries/LearnOpenGL samples.. can't do this with classes.
*/

export namespace JustGlfwWindow {
	int main();
}

export namespace GlfwWindowWithButton {
	int main();
}

export namespace OpenFileDialog {
	int main();
}

export namespace HelloTriangle {
	int main();
}

export namespace HelloTriangle_Oop {
	int main();
}

export namespace HelloTriangle_ProjectionViewModel {
	int main();
}

export namespace HelloTriangle_Perspective {
	int main();
}

export namespace HelloTriangle_Ortho {
	int main();
}

export namespace RotateByWASD {
	int main();
}

export namespace HelloPrimitives {
	int main();
}

export namespace CircleVsDisk {
	int main();
}

export namespace HelloTexture {
	int main();
}

export namespace HelloTexture_Oop {
	int main();
}

export namespace HelloTexture_Transparency {
	int main();
}

export namespace HelloTexture_Sphere {
	int main();
}

export namespace FreeCamera {
	int main();
}

export namespace FreeCamera_Oop {
	int main();
}

export namespace Lighting_Phong {
	int main();
}