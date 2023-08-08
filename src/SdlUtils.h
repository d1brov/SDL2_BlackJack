#pragma once

#include <SDL.h>

namespace sdl::surface::util {
	/**
	 * @brief Duplicates existing SDL_Surface* by creating new and copying.
	 * 
	 * @param source - surface to create copy from. 
	 * Does not modifies original surface but still not const* due to SDL's 
	 * requirements.
	 * @return copy of source surface.
	 * @throw SdlException
	 */
	SDL_Surface* DuplicateSdlSurface(SDL_Surface* source);

	/**
	 * @brief Fills destination surface's rectangle with color.
	 * 
	 * @param destination - surface to fill.
	 * @param color - to fill destination surface with.
	 * @throw SdlException
	 */
	void FillSdlSurface(SDL_Surface& destination, SDL_Color color);

	/**
	 * @brief Creates new colorless(transparent surface) of given dimensions.
	 * 
	 * @param width - in pixels
	 * @param height - in pixels
	 * @return created surface
	 * @throw SdlException
	 */
	SDL_Surface* MakeBlankSdlSurface(int width, int height);
}