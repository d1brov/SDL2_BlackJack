#pragma once

#include <SDL.h>

namespace sdl {
	void Initialize();
	void Deinitialize();

	namespace surface::util {
		SDL_Surface* DuplicateSdlSurface(SDL_Surface* source);
		void FillSdlSurface(SDL_Surface& destination, SDL_Color color);
		SDL_Surface* MakeBlankSdlSurface(int width, int height);
	}
}