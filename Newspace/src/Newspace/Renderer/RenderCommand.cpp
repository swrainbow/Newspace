#include "nspacepch.h"
#include "Newspace/Renderer/RenderCommand.h"

namespace Newspace {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}