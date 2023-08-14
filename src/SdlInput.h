#pragma once

#include "DebugPrint.h"
#include "EventPublisher.h"
#include "SdlEvent.h"

#include <SDL.h>

namespace sdl {
	using MouseButtonEvent = SdlEvent<SDL_MouseButtonEvent>;
	using MouseMotionEvent = SdlEvent<SDL_MouseMotionEvent>;
	using WindowEvent = SdlEvent<SDL_WindowEvent>;

	/**
	 * @brief Translates SDL events to SdlEvents
	 */
	class Input
		: public EventPublisher<MouseButtonEvent>
		, public EventPublisher<MouseMotionEvent>
		, public EventPublisher<WindowEvent>
	{
	public:
		Input() = default;
		Input(const Input& other) = delete;
		Input(Input&& rhs) = delete;
		void operator=(const Input&) = delete;
		void operator=(Input&& rhs) = delete;

		void Handle();

	private:
		SDL_Event event_{};
	};
}
