#pragma once
#include "Core.h"
#include "Newspace/LayerStack.h"
#include "Events/Event.h"
#include "Newspace/Events/ApplicationEvent.h"

#include "Window.h"

namespace Newspace {
	class NSPACE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	Application* createApplication();
}

