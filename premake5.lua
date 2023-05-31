workspace "Newspace"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Newspace/vendor/GLFW/include"
IncludeDir["Glad"] = "Newspace/vendor/Glad/include"
IncludeDir["ImGui"] = "Newspace/vendor/imgui"
IncludeDir["glm"] = "Newspace/vendor/glm"

include "Newspace/vendor/GLFW"
include "Newspace/vendor/Glad"
include "Newspace/vendor/imgui"

project "Newspace"
	location "Newspace"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nspacepch.h"
	pchsource "Newspace/src/nspacepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"NSPACE_PLATFORM_WINDOWS",
			"NSPACE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "NSPACE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NSPACE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NSPACE_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Newspace/vendor/spdlog/include",
		"Newspace/src",
		"Newspace/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Newspace"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"NSPACE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NSPACE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NSPACE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NSPACE_DIST"
		runtime "Release"
		optimize "on"
