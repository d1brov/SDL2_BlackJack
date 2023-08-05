#include "SdlUtils.h"

#include "DebugPrint.h"
#include "SdlException.h"

void sdl::Initialize() {
	DBG_PRINT("Initializing SDL subsystem\n");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        throw SdlException("Could not initialize SDL");
    }
}

void sdl::Deinitialize() {
	DBG_PRINT("Deinitializing SDL subsystem\n");
    SDL_Quit();
}