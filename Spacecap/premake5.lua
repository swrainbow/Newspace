project "Spacecap"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Newspace/vendor/spdlog/include",
		"%{wks.location}/Newspace/src",
		"%{wks.location}/Newspace/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}"
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
