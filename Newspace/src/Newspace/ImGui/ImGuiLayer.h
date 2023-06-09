#pragma once

#include "Newspace/Core/Layer.h"

#include "Newspace/Events/ApplicationEvent.h"
#include "Newspace/Events/KeyEvent.h"
#include "Newspace/Events/MouseEvent.h"

namespace Newspace {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
		void BlockEvents(bool block) { m_BlockEvents = block; }
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};
}