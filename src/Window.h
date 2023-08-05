#pragma once

#include <string>

class Window {
public:
	Window() = delete;
	Window(int width, int height, const std::string& title);
	~Window();

private:
	SDL_Window* ptr_;
};