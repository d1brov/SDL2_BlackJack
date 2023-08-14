#pragma once

namespace sdl {
	class SdlSubsystem
	{
	public:
		SdlSubsystem();
		~SdlSubsystem();

	private:
		void Init();
		void Deinit() noexcept;
	};
}
