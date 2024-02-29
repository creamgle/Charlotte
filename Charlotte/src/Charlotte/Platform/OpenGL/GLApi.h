#pragma once

#include "CharCore.h"
#include "Charlotte/Renderer/RendererApi.h"

namespace Charlotte {

    class GLApi : public RendererApi {
        public:
            GLApi() = default;
            ~GLApi() override = default;

            bool Initialise() override;

            void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
            void SetClearColor(float r, float g, float b, float a) override;

            void Clear() override;
    };

}