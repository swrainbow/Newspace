#include "nspacepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Newspace {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}