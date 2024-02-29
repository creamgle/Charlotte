#pragma once

#include "Charlotte/Core/PlatformDetection.h"

#ifdef CH_PLATFORM_MAC
    #ifdef CH_EXPORT
        #define CAPI __attribute__((visibility("default")))
    #else
        #define CAPI
    #endif
#endif

#include <memory>

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args) {
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args) {	
    return std::make_shared<T>(std::forward<Args>(args)...);
}