#pragma once
#include "Newspace.h"
#include <imgui/imgui.h>

namespace Newspace {
	class RayTracingEditorLayer :public Layer
	{
	public:
		RayTracingEditorLayer();
		virtual void OnAttach() override;
		virtual void OnUpdate(const TimeStep&) override;
		virtual void OnImGuiRender() override;
	private:
		void CreatFourSphereScene();
		void CreateMultiSphereScene();
	private:

		ImVec2 m_vec2RenderViewPortSize;

		Ref<ObjectContainer> m_spObjectContainer;
		Ref<RayTracingScene> m_spRayTracingScene;
		Ref<RayTracingCamera> m_spRayTracingCamera;

		Ref<Timer> m_spTimer;
		float m_fLastRenderTime;
	};
}
