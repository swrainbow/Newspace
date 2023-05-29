workspace "Newspace"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Newspace"
	location "Newspace"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NSPACE_PLATFORM_WINDOWS",
			"NSPACE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		

	filter "configurations:Debug"
		defines "NSPACE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NSPACE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NSPACE_Dist"
		symbols "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Newspace/vendor/spdlog/include",
		"Newspace/src"
	}

	links
	{
		"Newspace"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NSPACE_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "NSPACE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NSPACE_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NSPACE_Dist"
		symbols "On"

