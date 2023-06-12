#pragma once

#include <glm/glm.hpp>
#include "Newspace/Core/KeyCodes.h"
#include "Newspace/Core/MouseCodes.h"

namespace Newspace {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
