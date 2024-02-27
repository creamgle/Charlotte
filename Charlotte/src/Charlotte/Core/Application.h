#pragma once

/**
    Application should be used as the application
    entry point
*/

#include "CharCore.h"
#include "Charlotte/Core/Window.h"

namespace Charlotte {

    /**
        ApplicationConfig is essentially used as the startup
        configuration for the application, 
        used to specfiy things such as,
            - Window Width, Height, Title
            - Maybe what rendering API to use
    */
    struct ApplicationConfig {
        uint32_t Width;
        uint32_t Height;
        std::string Title;

        ApplicationConfig() = default;
    };

    class CAPI Application {
        public:
            Application() = default;
            virtual ~Application() = default;

            /**
                Used to run the application, handles numerous
                things such as opening the game window
                and initialising the renderer
            */
            bool Run(const ApplicationConfig& config);

        protected:
            /**
                Create() is called when (Application).Run() is called,
                if it returns false, the application will not run.
                used for loading errors and other random shit 
            */
            virtual bool Create() = 0;

        private:
            Window* mWindow = nullptr;
    };

}