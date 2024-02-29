workspace "Charlotte"
	configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

Includes = { }
Includes["Charlotte"] = "%{wks.location}/Charlotte/src"
Includes["GLFW"] = "%{wks.location}/Charlotte/vendor/glfw/include"
Includes["Glad"] = "%{wks.location}/Charlotte/vendor/glad/include"

include "Charlotte/vendor/glfw"
include "Charlotte/vendor/glad"

include "Charlotte"
include "Sandbox"
