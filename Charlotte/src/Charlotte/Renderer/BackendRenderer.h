#pragma once

#include "CharCore.h"
#include "RendererApi.h"

namespace Charlotte {

    class CAPI BackendRenderer {
        public:
            static bool Initialise();

            static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
            static void SetClearColor(float r, float g, float b, float a);

            static void Clear();

        private:
            static inline Ref<RendererApi> sApi;
    };

}