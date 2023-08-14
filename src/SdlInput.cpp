#include "SdlInput.h"

void sdl::Input::Handle() {
	while (SDL_PollEvent(&event_)) {
		switch (event_.type) {
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP: {
			EventPublisher<MouseButtonEvent>::NotifySubscribers(
				MouseButtonEvent(event_.button));
			break;
		}

		case SDL_MOUSEMOTION: {
			EventPublisher<MouseMotionEvent>::NotifySubscribers(
				MouseMotionEvent(event_.motion));
			break;
		}

		case SDL_WINDOWEVENT: {
			EventPublisher<WindowEvent>::NotifySubscribers(
				WindowEvent(event_.window));
			break;
		}

		default: break;
		}
	}
}
