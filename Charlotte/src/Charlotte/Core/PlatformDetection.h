#pragma once

/**
    PlatformDetection.h detects what platform the program
    is being ran on, currently only supports:
        - macOS (intel, arm might work but not sure)
*/

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #if TARGET_OS_MAC == 1
        #define CH_PLATFORM_MAC
    #endif
#endif