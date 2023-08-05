#pragma once

#include "Renderer.h"
#include <string>

class Window {
public:
	Window() = delete;
	Window(int width, int height, const std::string& title);
	~Window();

private:
	SDL_Window* ptr_;
	std::unique_ptr<Renderer> renderer_;
};