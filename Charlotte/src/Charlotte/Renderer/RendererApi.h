#pragma once

#include "CharCore.h"

namespace Charlotte {

    class CAPI RendererApi {
        public:
            virtual ~RendererApi() = default;

            static Ref<RendererApi> Create();

            virtual bool Initialise() = 0;

            virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
            virtual void SetClearColor(float r, float g, float b, float a) = 0;

            virtual void Clear() = 0;
    };

}