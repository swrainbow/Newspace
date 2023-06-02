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

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}