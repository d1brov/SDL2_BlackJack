#pragma once

#include "Event.h"

/**
 * @brief Interface for event subscriber.
 */
template <typename EventType>
class EventSubscriber {
public:
	virtual ~EventSubscriber() = default;
	virtual void OnEvent(const EventType& event) = 0;
};