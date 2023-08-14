#include "Renderer.h"

#include "DebugPrint.h"
#include "SdlException.h"

Renderer::Renderer(SDL_Window* window) {
    DBG_PRINT("Creating renderer\n");
    ptr_ = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ptr_ == nullptr) {
        throw SdlException("Could not create renderer");
    }

    if (SDL_SetRenderDrawBlendMode(ptr_, SDL_BLENDMODE_BLEND) < 0) {
        throw SdlException("Could not set renderer blend mode");
    }

    if (SDL_SetHint(
        SDL_HINT_RENDER_SCALE_QUALITY,
        std::to_string(SDL_ScaleModeBest).c_str()) == SDL_FALSE) {
        throw SdlException("Could not set render anisotropic filtering");
    }
}

Renderer::~Renderer() {
    FreeTextureMap();
    DBG_PRINT("Destroying renderer\n");
    SDL_DestroyRenderer(ptr_);
}

void Renderer::AddSurfaceToBuffer(Surface* surface, Rectangle rectangle, double angle) {
    if (SDL_RenderCopyEx(
        ptr_,
        RenderTexture(surface->ptr_),
        surface->clip_.get(),
        &rectangle,
        angle,
        nullptr,
        SDL_FLIP_NONE) < 0) {
        throw SdlException("Cannot display object");
    }
}

void Renderer::ClearBuffer() {
    if (SDL_RenderClear(ptr_) < 0) {
        throw SdlException("Render clearing error");
    }
}

void Renderer::FreeTextureMap() noexcept {
    DBG_FMT_PRINT("Freeing textures [{}] \n", texture_map_.size());
    for (const auto& [surface, texture] : texture_map_) {
        SDL_DestroyTexture(texture);
    }
    texture_map_.clear();
}

void Renderer::DisplayBuffer() {
    SDL_RenderPresent(ptr_);
}

SDL_Texture* Renderer::RenderTexture(SDL_Surface* surface) {
    if (texture_map_.contains(surface)) {
        return texture_map_.at(surface);
    }
    else {
        if (auto texture{ SDL_CreateTextureFromSurface(ptr_, surface) }) {
            DBG_PRINT(std::format("Creating texture [{}]\n", texture_map_.size()+1));
            texture_map_[surface] = texture;
            return texture;
        }
        else {
            throw SdlException("Cannot render texture");
        }
    }
}