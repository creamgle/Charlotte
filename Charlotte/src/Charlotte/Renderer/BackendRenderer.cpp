#include "BackendRenderer.h"
#include "Charlotte/Core/Log.h"

namespace Charlotte {

    bool BackendRenderer::Initialise() {
        sApi = RendererApi::Create();
        if (!sApi->Initialise()) {
            LogFatal("Failed to initialise rendering api!");
            return false;
        }

        return true;
    }

    void BackendRenderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
        sApi->SetViewport(x, y, width, height);
    }

    void BackendRenderer::SetClearColor(float r, float g, float b, float a) {
        sApi->SetClearColor(r, g, b, a);
    }

    void BackendRenderer::Clear() {
        sApi->Clear();
    }

}