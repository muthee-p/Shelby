workspace "Shelby"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist" --distribution
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" --configurations

--include dir relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Shelby/vendor/GLFW/include"
IncludeDir["Glad"] = "Shelby/vendor/GLFW/include"

include "Shelby/vendor/GLFW"
include "Shelby/vendor/Glad"

project "Shelby"
	location "Shelby"
	kind "SharedLib" --dynamic library/dll file
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sbpch.h"
	pchsource "Shelby/src/sbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links 
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows" 
		cppdialect "C++17" 
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS",
			"SB_BUILD_DLL"
		}

		postbuildcommands --copy the dll file to client app
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Vice")
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SB_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "SB_DIST"
		buildoptions "/MD"
		symbols "On"
	
---------------------------------------client--------------------------------

project "Vice"
	location "Vice"
	kind "ConsoleApp" --exe file
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Shelby/vendor/spdlog/include",
		"Shelby/src"
	}

	links
	{
		"Shelby"
	}

	filter "system:windows" 
		cppdialect "C++17" 
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "SB_RELEASE"
		buildoptions "/MD"
		symbols "On"

	filter "configurations:Dist"
		defines "SB_DIST"
		buildoptions "/MD"
		symbols "On"