#include "pch.h"

using namespace std;

namespace external_tools_tests
{
	TEST(ExternalToolsTests, powershell_7_should_be_installed_and_added_to_PATH)
	{
		EXPECT_EQ(system("pwsh --version"), 0);
	}

	TEST(ExternalToolsTests, git_should_be_installed_and_added_to_PATH)
	{
		EXPECT_EQ(system("git --version"), 0);
	}

	TEST(ExternalToolsTests, cmake_should_be_installed_and_added_to_PATH)
	{
		EXPECT_EQ(system("cmake --version"), 0);
	}

	TEST(ExternalToolsTests, msbuild_should_be_added_to_PATH)
	{
		EXPECT_EQ(system("msbuild --version"), 0);
	}
}
