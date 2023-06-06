#include "nspacepch.h"
#include "Newspace/Core/Input.h"

#ifdef NSPACE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace Newspace {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef HZ_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		NSPACE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}