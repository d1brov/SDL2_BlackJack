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

void Window::Display(std::shared_ptr<Drawable> object) {
    displayed_objects_.push_back(object);
}

void Window::Refresh() {
    renderer_->ClearBuffer();

    for (auto it{ displayed_objects_.begin() }; it != displayed_objects_.end() ;) {
        if (auto drawable{ it->lock() }) {
            renderer_->AddSurfaceToBuffer(
                drawable->GetSurface(), 
                drawable->rectangle_,
                drawable->angle_);
            it++;
        }
        else {
            it = displayed_objects_.erase(it);
        }
    }

    renderer_->DisplayBuffer();
}

void Window::Undisplay(std::shared_ptr<Drawable> object) {
    displayed_objects_.remove_if(
        [&object](std::weak_ptr<Drawable> it) {
            return it.expired() || it.lock() == object;
        }
    );
}