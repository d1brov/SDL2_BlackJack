#include "SdlSubsystem.h"

#include "DebugPrint.h"
#include "SdlException.h"

#include <SDL.h>

using namespace sdl;

const SdlSubsystem instance;

SdlSubsystem::SdlSubsystem() {
	Init();
}

SdlSubsystem::~SdlSubsystem() {
	Deinit();
}

void SdlSubsystem::Init() {
	DBG_PRINT("Initializing SDL subsystem\n");
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		throw SdlException("Could not initialize SDL");
	}
}

void SdlSubsystem::Deinit() noexcept {
	DBG_PRINT("Deinitializing SDL subsystem\n");
	SDL_Quit();
}