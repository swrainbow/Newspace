#pragma once

#ifdef NSPACE_PLATFORM_WINDOWS
extern Newspace::Application* Newspace::createApplication();

int main(int argc, char** argv)
{
	auto app = Newspace::createApplication();
	app->run();
	delete app;

}
#endif // DEBUG