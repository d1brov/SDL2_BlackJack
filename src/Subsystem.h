#pragma once

namespace sdl {
	/**
	 * @brief SDL subsystem object. 
	 * 
	 * Inits SDL subsystems on creation and deinits on destruction.
	 */
	class Subsystem {
	public:
		Subsystem();
		~Subsystem();
	};
}