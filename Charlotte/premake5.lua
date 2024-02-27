project "Charlotte"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"

    targetdir("%{wks.location}/bin/" .. outputdir .. "%{prj.name}")
    objdir("%{wks.location}/bin/obj/" .. outputdir .. "%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src/",
        "%{Includes.GLFW}"
    }

    defines {
        "CH_EXPORT",
        "GLFW_INCLUDE_NONE"
    }

    links {
        "GLFW"
    }

    -- Mac specific libraries for OpenGL and GLFW to work (and possibly others down the road)
    filter "system:macosx"
        links {"OpenGL.framework", "Cocoa.framework", "IOKit.framework", "CoreFoundation.framework", "CoreAudio.framework", "CoreVideo.framework", "AudioToolbox.framework"}

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"