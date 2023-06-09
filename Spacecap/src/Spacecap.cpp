#include <Newspace.h>
#include <Newspace/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Newspace {

	class Spacecap : public Application
	{
	public:
		Spacecap()
			: Application("Spacecap")
		{
			PushLayer(new EditorLayer());
		}

		~Spacecap()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Spacecap();
	}

}