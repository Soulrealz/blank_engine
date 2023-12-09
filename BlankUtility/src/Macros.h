#pragma once

// Using this macro will automate the import/export process
// If defined in premake it will turn on to dllexport
// This is windows only
#ifdef BLANK_BUILD_DLL
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif