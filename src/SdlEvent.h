#pragma once

#include "Event.h"

/**
 * @brief Event wrapper for SDL events data.
 */
template<typename SdlEventDataType>
struct SdlEvent : public Event {

	SdlEvent() = delete;

	// Definition has to be in header for correct work of templated event
	explicit SdlEvent(SdlEventDataType data) : data_(data) {
	}

	SdlEventDataType data_;
};