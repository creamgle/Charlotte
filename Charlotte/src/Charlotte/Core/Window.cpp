#include "Window.h"
#include "CharCore.h"

#ifdef CH_PLATFORM_MAC
    #include "Charlotte/Platform/macOS/macOS_Window.h"
#endif

namespace Charlotte {

    Scope<Window> Window::CreateWindow(const WindowData& data) {
        #ifdef CH_PLATFORM_MAC
            return CreateScope<macOS_Window>(data);
        #endif
        return nullptr;
    }

}