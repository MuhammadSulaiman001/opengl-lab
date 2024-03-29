import Sample;

#include <iostream>
#include <functional>

using namespace std;

vector<std::pair<string, function<int()>>> demos = {
	{
		"Show empty Glfw window (minimal code)", []()-> int
		{
			return JustGlfwWindow::main();
		},
	},
	{
		"Glfw Window with button", []()-> int
		{
			return GlfwWindowWithButton::main();
		},
	},
	{
		"Show triangle (minimal code)", []()-> int
		{
			return HelloTriangle::main();
		},
	},
	{
		"Show triangle (OOP code)", []()-> int
		{
			return HelloTriangle_Oop::main();
		},
	},
	{
		"Show triangle (projection x view x model)", []()-> int
		{
			return HelloTriangle_ProjectionViewModel::main();
		},
	},
	{
		"Show triangle (perspective projection x view` x model`)", []()-> int
		{
			return HelloTriangle_Perspective::main();
		},
	},
	{
		"Show triangle (orthographic projection)", []()-> int
		{
			return HelloTriangle_Ortho::main();
		},
	},
	{
		"Primitives", []()-> int
		{
			return HelloPrimitives::main();
		},
	},
	{
		"Circle vs. Disk", []()-> int
		{
			return CircleVsDisk::main();
		},
	},
	{
		"Rotate by WASD", []()-> int
		{
			return RotateByWASD::main();
		},
	},
	{
		"Hello texture (minimal code)", []()-> int
		{
			return HelloTexture::main();
		},
	},
	{
		"Hello texture (OOP)", []()-> int
		{
			return HelloTexture_Oop::main();
		},
	},
	{
		"Hello texture - Transparent for real", []()-> int
		{
			return HelloTexture_Transparency::main();
		},
	},
	{
		"One VAO, Two textures", []()-> int
		{
			return One_VAO_Two_Textures::main();
		},
	},
	{
		"Combine Textures", []()-> int
		{
			return Combine_Textures::main();
		},
	},
	{
		"Free Camera (minimal code)", []()-> int
		{
			return FreeCamera::main();
		},
	},
	{
		"Free Camera (OOP)", []()-> int
		{
			return FreeCamera_Oop::main();
		},
	},
	{
		"Lighting - Phong model", []()-> int
		{
			return Lighting_Phong::main();
		},
	},
	// TODO: loading the model causes the textures in demos 12/13 to not load correctly!!
	// {
	// 	"Hello Model", []()-> int
	// 	{
	// 		return HelloModel::main();
	// 	},
	// },
	// TODO
	// {
	// 	"Blending", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO
	// {
	// 	"Hello SkyBox", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// {
	// 	// Bug: when reopening the sample nothing gets rendered!
	// 	// Bug Fix: texture repetition
	// 	"Hello texture - Sphere", []()-> int
	// 	{
	// 		return HelloTexture_Sphere::main();
	// 	},
	// },
	// todo: revisit https://github.com/MuhammadSulaiman001/opengl-lab/discussions/17
	// {
	// 	"File Picker (A.K.A OpenFileDialog)", []()-> int
	// 	{
	// 		return OpenFileDialog::main();
	// 	},
	// },
	// TODO
	// {
	// 	"Choose Texture With File Picker", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// {
	// 	"Analogue Clock", []()-> int
	// 	{
	// 		return AnalogueClock::main();
	// 	},
	// },
	// TODO
	// {
	// 	"Browse/Play audio file", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
	// TODO: Draw Text
	// {
	// 	"Draw Text", []()-> int
	// 	{
	// 		throw NotImplementedException();
	// 	},
	// },
};

int main()
{
	auto keepShowingDemos = true;
	auto demoNumber = -1;

	while (keepShowingDemos)
	{
		system("cls");
		cout << "Enter demo number [1, " << demos.size() << "] to show it, enter any other value to break..." << endl;
		for (int i = 0; i < demos.size(); ++i)
		{
			auto& description = demos[i].first;
			cout << i + 1 << ") " << description << endl;
		}
		cin >> demoNumber;
		keepShowingDemos = 1 <= demoNumber && demoNumber <= demos.size();
		if (!keepShowingDemos)
			break;
		// index passed by the user starts from 1, hence, -1
		demos[demoNumber - 1].second();
	}
	return 0;
}
