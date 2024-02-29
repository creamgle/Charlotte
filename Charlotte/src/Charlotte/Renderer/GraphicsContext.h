#pragma once

#include "CharCore.h"

namespace Charlotte {

    class CAPI GraphicsContext {
        public:
            virtual ~GraphicsContext() = default;

            static Scope<GraphicsContext> Create();

            virtual bool Initialise(void* handle) = 0;
            virtual void SwapBuffers() = 0;
            virtual void Shutdown() = 0;
    };

}