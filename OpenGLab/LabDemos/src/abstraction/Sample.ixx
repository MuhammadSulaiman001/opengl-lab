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

export namespace HelloOopTriangle {
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

export namespace FreeCamera {
	int main();
}