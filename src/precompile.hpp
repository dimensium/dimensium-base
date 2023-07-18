#ifndef _PRECOMPILE_HPP
#define _PRECOMPILE_HPP
/*
    the file is touched for the Visual Studio's compile system.
*/
#if defined(_WIN32)
    #if defined(dimensium_exports)
        #define dimensium_export __declspec(dllexport)   
    #else
        #define dimensium_export __declspec(dllimport)
    #endif
#else
    #define dimensium_export
#endif

#endif // _PRECOMPILE_HPP