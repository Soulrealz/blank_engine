include "dependencies/conandeps.premake5.lua"

workspace "BlankSpace"
    configurations { "Debug", "Release"} --"Dist"?
    architecture "x86_64"
    --startproject SamplePrj
    --location used for wks.location
    location "./"

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
            "%{prj.location}/**.h", "%{prj.location}/**.hpp", "%{prj.location}/**.hh",
            "%{prj.location}/**.c", "%{prj.location}/**.cpp", "%{prj.location}/**.cc",
            "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.ini", "%{prj.location}/**.md",
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