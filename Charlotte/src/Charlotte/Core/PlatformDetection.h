#pragma once

#if defined(__APPLE__)
    #include <TargetConditionals.h>

    #if TARGET_OS_MAC == 1
        #define CH_PLATFORM_MAC
    #endif
#endif