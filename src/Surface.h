#pragma once

#include "Common.h"

#include <memory>

class Renderer;

class Surface {
	friend Renderer;

public:
	Surface() = delete;
	Surface(int width, int height, SDL_Color color);
	Surface(const Surface& other);
	Surface(Surface&& other) noexcept;
	~Surface();
	Surface& operator=(const Surface& rhs);
	Surface& operator=(Surface&& rhs) noexcept;
	Rectangle GetClip() const;
	void SetClip(Rectangle clip);

private:
	SDL_Surface* ptr_{};
	std::unique_ptr<Rectangle> clip_{};
};