#pragma once

#include "Drawable.h"
#include "Renderer.h"

#include <deque>
#include <string>

class Window {
public:
	Window() = delete;
	Window(int width, int height);
	~Window();

	unsigned int GetId() const;
	void SetTitle(const std::string& title);

	void Display(std::shared_ptr<Drawable> object);
	void Refresh();
	void Resize(int width, int height);
	void Undisplay(std::shared_ptr<Drawable> object);

private:
	SDL_Window* ptr_;
	std::unique_ptr<Renderer> renderer_;
	std::deque<std::weak_ptr<Drawable>> displayed_objects_{};
};