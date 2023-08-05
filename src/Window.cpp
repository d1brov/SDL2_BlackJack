#include "Window.h"

#include "DebugPrint.h"
#include "SdlException.h"

Window::Window(int width, int height, const std::string& title) {
    DBG_PRINT("Creating window\n");
    ptr_ = SDL_CreateWindow(
        title.c_str(),
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (ptr_ == nullptr) {
        throw SdlException("Could not create window");
    }

    renderer_ = std::make_unique<Renderer>(ptr_);
}

Window::~Window() {
    DBG_PRINT("Destroying window\n");
    SDL_DestroyWindow(ptr_);
}