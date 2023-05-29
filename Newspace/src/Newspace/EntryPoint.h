#pragma once

#ifdef NSPACE_PLATFORM_WINDOWS
extern Newspace::Application* Newspace::createApplication();

int main(int argc, char** argv)
{
	Newspace::Log::Init();
	//Newspace::Log::GetCoreLogger()->warn("Initialized Log!");
	//Newspace::Log::GetClientLogger()->info("Client Hello");
	NSPACE_CORE_WARN("Initialized Log!");
	int a = 1;
	NSPACE_INFO("Core var={0}", a);

	auto app = Newspace::createApplication();
	app->run();
	delete app;

}
#endif // DEBUG