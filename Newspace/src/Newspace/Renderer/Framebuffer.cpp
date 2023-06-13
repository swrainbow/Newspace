#include "nspacepch.h"
#include "Newspace/Renderer/Framebuffer.h"

#include "Newspace/Renderer/Renderer.h"

#include "Platform/OpenGL/OpenGLFramebuffer.h"

namespace Newspace {

	Ref<Framebuffer> Framebuffer::Create(const FramebufferSpecification& spec)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    NSPACE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		NSPACE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}