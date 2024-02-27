#pragma once

#include "Charlotte/Core/PlatformDetection.h"

#ifdef CH_PLATFORM_MAC
    #ifdef CH_EXPORT
        #define CAPI __attribute__((visibility("default")))
    #else
        #define CAPI
    #endif
#endif