include "./vendor/premake/premake_customization/solution_items.lua"

workspace "Newspace"
	architecture "x86_64"
	startproject "Spacecap"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Newspace/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Newspace/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Newspace/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/Newspace/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/Newspace/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/Newspace/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Newspace/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Newspace/vendor/ImGuizmo"
IncludeDir["Box2D"] = "%{wks.location}/Newspace/vendor/Box2D/include"

group "Dependencies"
	include "vendor/premake"
	include "Newspace/vendor/Box2D"
	include "Newspace/vendor/GLFW"
	include "Newspace/vendor/Glad"
	include "Newspace/vendor/imgui"
	include "Newspace/vendor/yaml-cpp"
group ""

include "Newspace"
include "Sandbox"
include "Spacecap"
