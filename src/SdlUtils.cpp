#include "SdlUtils.h"

#include "DebugPrint.h"
#include "SdlException.h"

SDL_Surface* sdl::surface::util::DuplicateSdlSurface(SDL_Surface* source) {
	if (auto copy{ SDL_ConvertSurface(source, source->format, SDL_SWSURFACE) }) {
		DBG_FMT_PRINT("Duplicating surface [{}]\n", ++surface_counter);
		return copy;
	}
	else {
		throw SdlException("Cannot duplicate surface");
	}
}

void sdl::surface::util::FillSdlSurface(SDL_Surface& destination, SDL_Color color) {
	if (SDL_FillRect(
		&destination, nullptr,
		SDL_MapRGBA(
			destination.format, color.r, color.g, color.b, color.a)) < 0) {
		throw SdlException("Cannot fill SDL_Surface");
	}
}

SDL_Surface* sdl::surface::util::MakeBlankSdlSurface(int width, int height) {
	if (auto surface{ SDL_CreateRGBSurface(
		0, width, height, 32,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
		0xff000000) }) {
		DBG_FMT_PRINT("Creating surface [{}]\n", ++surface_counter);
		return surface;
	}
	else {
		throw SdlException("Cannot make blank SDL_Surface");
	}
}