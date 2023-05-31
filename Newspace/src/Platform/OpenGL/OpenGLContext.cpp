#include "nspacepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Newspace {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		NSPACE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		NSPACE_CORE_ASSERT(status, "Failed to initialize Glad!");

		//NSPACE_CORE_INFO("OpenGL Info:");
		//NSPACE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		//NSPACE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//NSPACE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}