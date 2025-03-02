#pragma once

#ifdef SB_PLATFORM_WINDOWS

extern Shelby::Application* Shelby::CreateApplication();

int main(int argc, char** argv)
{
	Shelby::Log::Init();
	SB_CORE_WARN("Initialized Log!");
	int a = 790;
	SB_INFO("Shelloo! Var={0}", a);

	printf("shello");
	auto app = Shelby::CreateApplication();
	app->Run();
	delete app;
}
#endif