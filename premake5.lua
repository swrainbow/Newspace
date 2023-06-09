workspace "Newspace"
	architecture "x86_64"
	startproject "Spacecap"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Newspace/vendor/GLFW/include"
IncludeDir["Glad"] = "Newspace/vendor/Glad/include"
IncludeDir["ImGui"] = "Newspace/vendor/imgui"
IncludeDir["glm"] = "Newspace/vendor/glm"
IncludeDir["stb_image"] = "Newspace/vendor/stb_image"
IncludeDir["entt"] = "Newspace/vendor/entt/include"



group "Dependencies"
	include "Newspace/vendor/GLFW"
	include "Newspace/vendor/Glad"
	include "Newspace/vendor/imgui"
group ""

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
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
		
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
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


project "Spacecap"
	location "Spacecap"
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Newspace"
	}

	filter "system:windows"
		systemversion "latest"
		
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

