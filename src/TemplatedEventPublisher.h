#pragma once

#include <memory>

/**
 * @brief Base for EventPublisher. Needed for correct instantiation of templated events.
 */
template <typename EventType>
class TemplatedEventPublisher {
public:
	virtual ~TemplatedEventPublisher() = default;

	virtual void NotifySubscribers(const EventType& event) = 0;

	virtual void AddSubscriber(
		std::shared_ptr<EventSubscriber<EventType>> subscriber) = 0;

	virtual void RemoveSubscriber(
		std::shared_ptr<EventSubscriber<EventType>> subscriber) = 0;
};