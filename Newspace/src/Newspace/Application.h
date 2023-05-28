#pragma once
#include "Core.h"


namespace Newspace {
	class NSPACE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}

