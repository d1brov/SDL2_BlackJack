#include "Window.h"

#include "DebugPrint.h"
#include "SdlException.h"

Window::Window(int width, int height) {
    DBG_PRINT("Creating window\n");
    ptr_ = SDL_CreateWindow(
        nullptr,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    if (ptr_ == nullptr) {
        throw SdlException("Could not create window");
    }

    renderer_ = std::make_unique<Renderer>(ptr_);
}

Window::~Window() {
    DBG_PRINT("Destroying window\n");
    SDL_DestroyWindow(ptr_);
}

unsigned int Window::GetId() const {
    return SDL_GetWindowID(ptr_);
}

void Window::SetTitle(const std::string& title) {
    SDL_SetWindowTitle(ptr_, title.c_str());
}

void Window::Display(std::shared_ptr<Drawable> object) {
    // Check if object is already displayed
    auto found_it{ std::ranges::find_if(displayed_objects_,
         [&object](std::weak_ptr<Drawable> it) {
             return (!it.expired() && it.lock() == object);
         }) 
    };

    if (found_it == displayed_objects_.end()) {
        displayed_objects_.push_back(object);
    }
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

void Window::Resize(int width, int height) {
    SDL_SetWindowSize(ptr_, width, height);
}

void Window::Undisplay(std::shared_ptr<Drawable> object) {
    std::erase_if(displayed_objects_, 
        [&object](std::weak_ptr<Drawable> it) {
            return it.expired() || it.lock() == object;
        });
}