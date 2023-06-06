#include "nspacepch.h"
#include "Newspace/Core/Window.h"

#ifdef NSPACE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Newspace
{

	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef NSPACE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		NSPACE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}