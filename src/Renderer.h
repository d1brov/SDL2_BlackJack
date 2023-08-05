#pragma once

#include "Surface.h"

#include <unordered_map>

class Renderer {
public:
	Renderer() = delete;
	explicit Renderer(SDL_Window* window);
	~Renderer();

	void AddSurfaceToBuffer(
		Surface* surface, Rectangle rectangle, double angle = 0);
	void ClearBuffer();
	void DisplayBuffer();

private:
	int texture_counter_{};
	SDL_Texture* RenderTexture(SDL_Surface* surface);
	SDL_Renderer* ptr_{};
	std::unordered_map<SDL_Surface*, SDL_Texture*> texture_map_{};
};