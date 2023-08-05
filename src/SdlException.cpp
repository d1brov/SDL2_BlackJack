#include "SdlException.h"

#include <SDL.h>

#include <format>

SdlException::SdlException() 
	: message_(std::format("{}", SDL_GetError())) {
}

SdlException::SdlException(const std::string& message) 
	: message_(std::format("{}\n{}", message, SDL_GetError())) {
}

const char* SdlException::what() const noexcept {
	return message_.c_str();
}
