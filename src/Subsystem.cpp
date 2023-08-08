#include "Subsystem.h"

#include "DebugPrint.h"
#include "SdlException.h"

#include <SDL.h>

const sdl::Subsystem instance;

sdl::Subsystem::Subsystem() {
	DBG_PRINT("Initializing SDL subsystem\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw SdlException("Could not initialize SDL");
	}
}

sdl::Subsystem::~Subsystem() {
	DBG_PRINT("Deinitializing SDL subsystem\n");
	SDL_Quit();
}