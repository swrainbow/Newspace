#pragma once

#include "Newspace/Core/Base.h"
#include "Newspace/Core/Log.h"
#include "Newspace/Scene/Scene.h"
#include "Newspace/Scene/Entity.h"

namespace Newspace {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}