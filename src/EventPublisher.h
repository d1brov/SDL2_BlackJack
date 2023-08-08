#pragma once

#include "EventSubscriber.h"
#include "TemplatedEventPublisher.h"

#include <deque>

/**
 * @brief Manages events subscriber list.
 * Functions definitions have to be in the header file for correct generation of templated classes.
 */
template<typename Event>
class EventPublisher : public TemplatedEventPublisher<Event> {
public:

	/**
	 * @brief Notifies subscribers about event. Removes expired subscribers simultaneously.
	 * 
	 * \param event - to notify subscribers about.
	 */
	void NotifySubscribers(const Event& event) override {
		for (auto it{ subscribers_.begin() }; it != subscribers_.end();) {
			if (auto subscriber{ it->lock() }) {
				subscriber->OnEvent(event);
				it++;
			}
			else {
				it = subscribers_.erase(it);
			}
		}
	}

	/**
	 * @brief Adds subscriber to notification list.
	 * 
	 * \param subscriber - to be added to subscription list. Does not increment use count.
	 */
	void AddSubscriber(
		std::shared_ptr<EventSubscriber<Event>> subscriber) override {
		/*
			Check if the subscriber is already added to subscription list
			std::find or std::ranges::find does not work with templates 
			so I had to do a manual check
		*/
		for (const auto& sub_ptr : subscribers_) {
			if (auto sub_it{ sub_ptr.lock() }; sub_it == subscriber) {
				return;
			}
		}
		subscribers_.push_back(subscriber);
	}

	/**
	 * @brief Removes subscriber from subscriber list.
	 * 
	 * \param subscriber - to be removed from subscription list.
	 */
	void RemoveSubscriber(
		std::shared_ptr<EventSubscriber<Event>> subscriber) override {

		for (auto it{ subscribers_.begin() }; it != subscribers_.end(); it++) {
			if (it->lock() == subscriber) {
				subscribers_.erase(it);
				return;
			}
		}
	}

private:
	std::deque<std::weak_ptr<EventSubscriber<Event>>> subscribers_;
};