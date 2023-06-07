#include "nspacepch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Newspace {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		NSPACE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		NSPACE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		NSPACE_CORE_ASSERT(status, "Failed to initialize Glad!");
		//std::cout << " Vendor: ==============" << glGetString(GL_VENDOR) << std::endl;
		//NSPACE_CORE_INFO("OpenGL Info:");
		//NSPACE_CORE_TRACE("  Vendor: {0}", glGetString(GL_VENDOR));
		//NSPACE_CORE_TRACE("  Renderer: {0}", glGetString(GL_RENDERER));
		//NSPACE_CORE_TRACE("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		NSPACE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}