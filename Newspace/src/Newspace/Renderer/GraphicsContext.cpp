#include "nspacepch.h"
#include "Newspace/Renderer/GraphicsContext.h"

#include "Newspace/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Newspace {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    NSPACE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		NSPACE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}