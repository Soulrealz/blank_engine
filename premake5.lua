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
            "%{prj.location}/headers/**.h", "%{prj.location}/headers/**.hpp", "%{prj.location}/headers/**.hh",
            "%{prj.location}/comp/**.c", "%{prj.location}/cpp/**.cpp", "%{prj.location}/cpp/**.cc",
            "%{prj.location}/**.lua", "%{prj.location}/**.txt", "%{prj.location}/**.ini", "%{prj.location}/**.md",
        }

        --filter must be at the end always
        filter "configurations:Debug"
            defines {"DEBUG, _DEBUG"}
            symbols "On"
        filter {}    
        
        filter "configurations:Release"
            defines {"NDEBUG"}
            symbols "On"
        filter {}

