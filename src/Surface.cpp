#include "Surface.h"

#include "DebugPrint.h"
#include "SdlException.h"
#include "SdlUtils.h"

using namespace sdl::surface::util;

Surface::Surface(int width, int height, SDL_Color color) 
	: ptr_(MakeBlankSdlSurface(width, height)) {
	FillSdlSurface(*ptr_, color);
}

Surface::Surface(const Surface& other) 
	: ptr_(DuplicateSdlSurface(other.ptr_))
	, clip_(other.clip_ ? std::make_unique<Rectangle>(*other.clip_) : nullptr) {
	DBG_PRINT("Surface copy c-tor\n");
}

Surface::Surface(Surface&& other) noexcept 
	: ptr_(other.ptr_)
	, clip_(std::move(other.clip_)) {
	other.ptr_ = nullptr;
	DBG_PRINT("Surface move c-tor\n");
}

Surface::~Surface() {
	DBG_FMT_PRINT("Freeing surface [{}]\n", surface_counter--);
	SDL_FreeSurface(ptr_);
}

Surface& Surface::operator=(const Surface& rhs) {
	if (this != &rhs) {
		ptr_ = DuplicateSdlSurface(rhs.ptr_);
		clip_ = rhs.clip_ ? std::make_unique<Rectangle>(*rhs.clip_) : nullptr;
	}
	DBG_PRINT("Surface copy operator=\n");
	return *this;
}

Surface& Surface::operator=(Surface&& rhs) noexcept {
	if (this != &rhs) {
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
		clip_ = std::move(rhs.clip_);
	}
	DBG_PRINT("Surface move operator=\n");
	return *this;
}

Rectangle Surface::GetClip() const {
	return clip_ ? *clip_ : Rectangle();
}

void Surface::SetClip(Rectangle clip) {
	clip_ = std::make_unique<Rectangle>(clip);
}