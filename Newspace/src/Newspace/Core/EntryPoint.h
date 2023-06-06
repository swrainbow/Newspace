#pragma once
#include "Newspace/Core/Core.h"

#ifdef NSPACE_PLATFORM_WINDOWS
extern Newspace::Application* Newspace::CreateApplication();

int main(int argc, char** argv)
{
	Newspace::Log::Init();

	NSPACE_PROFILE_BEGIN_SESSION("Startup", "NewspaceProfile-Startup.json");
	auto app = Newspace::CreateApplication();
	NSPACE_PROFILE_END_SESSION();

	NSPACE_PROFILE_BEGIN_SESSION("Runtime", "NewspaceProfile-Runtime.json");
	app->Run();
	NSPACE_PROFILE_END_SESSION();

	NSPACE_PROFILE_BEGIN_SESSION("Startup", "NewspaceProfile-Shutdown.json");
	delete app;
	NSPACE_PROFILE_END_SESSION();
}
#endif // DEBUG