#pragma once

#ifdef SB_PLATFORM_WINDOWS

extern Shelby::Application* Shelby::CreateApplication();

int main(int argc, char** argv)
{
	printf("shello");
	auto app = Shelby::CreateApplication();
	app->Run();
	delete app;
}
#endif