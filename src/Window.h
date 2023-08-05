#pragma once

#include "Drawable.h"
#include "Renderer.h"

#include <list>
#include <string>

class Window {
public:
	Window() = delete;
	Window(int width, int height, const std::string& title);
	~Window();

	void Display(std::shared_ptr<Drawable> object);
	void Refresh();
	void Undisplay(std::shared_ptr<Drawable> object);

private:
	SDL_Window* ptr_;
	std::unique_ptr<Renderer> renderer_;
	std::list<std::weak_ptr<Drawable>> displayed_objects_{};
};