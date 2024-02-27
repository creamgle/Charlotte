project "Sandbox"
    kind "ConsoleApp"
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
        "%{Includes.Charlotte}"
    }

    links {
        "Charlotte"
    }

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"