#include <Newspace.h>

class SandBox : public Newspace::Application
{
public:
	SandBox()
	{

	}
	~SandBox()
	{

	}
};

Newspace::Application* Newspace::createApplication()
{
	return new SandBox();
}
