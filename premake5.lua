include "dependencies/conandeps.premake5.lua"

workspace "BlankSpace"
    configurations { "Debug", "Release"} --"Dist"?
    architecture "x86_64"
    --startproject SamplePrj
    --location used for wks.location
    location "./"
    startproject "BlankEngine"

    project "BlankUtility"
        kind "SharedLib"
        language "C++"
        cppdialect "C++20"

        --binary and object locations
        targetdir "%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/"
        objdir "%{wks.location}/build/obj/%{cfg.architecture}-%{cfg.buildcfg}/"

        location "%{wks.location}/BlankUtility"
        files
        {
            "%{prj.location}/src/**.h", "%{prj.location}/src/**.hpp", "%{prj.location}/src/**.hh",
            "%{prj.location}/src/**.c", "%{prj.location}/src/**.cpp", "%{prj.location}/src/**.cc",
            "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.ini", "%{prj.location}/**.md",
        }

        --This turns on declspec export
        defines
        {
            "BLANK_BUILD_DLL"
        }

        filter "configurations:Debug"
            defines {"DEBUG"}
            symbols "On"
        filter {}    
        
        filter "configurations:Release"
            defines {"NDEBUG"}
            symbols "On"
        filter {}

        conan_setup()

    project "BlankEngine"       
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++20"

        --binary and object locations
        targetdir "%{wks.location}/build/bin/%{cfg.architecture}-%{cfg.buildcfg}/"
        objdir "%{wks.location}/build/obj/%{cfg.architecture}-%{cfg.buildcfg}/"

        location "%{wks.location}/BlankEngine"
        files
        {
            "%{prj.location}/src/**.h", "%{prj.location}/src/**.hpp", "%{prj.location}/src/**.hh",
            "%{prj.location}/src/**.c", "%{prj.location}/src/**.cpp", "%{prj.location}/src/**.cc",
            "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.ini", "%{prj.location}/**.md",
        }

        includedirs
        {
            "BlankUtility/src"
        }

        links
        {
            "BlankUtility"
        }

        filter "configurations:Debug"
            defines {"DEBUG"}
            symbols "On"
        filter {}    
        
        filter "configurations:Release"
            defines {"NDEBUG"}
            symbols "On"
        filter {}

        conan_setup()