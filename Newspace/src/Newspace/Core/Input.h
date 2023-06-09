#pragma once

#include "Newspace/Core/Base.h"
#include "Newspace/Core/KeyCodes.h"
#include "Newspace/Core/MouseCodes.h"

namespace Newspace {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
