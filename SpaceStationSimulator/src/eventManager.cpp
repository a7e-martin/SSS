#include "eventManager.h"
#include "log.h"
#include "gvars.h"

bool EventManager::AddListener(IEventData::id_t id, EventDelegate proc)
{
	auto fi = _eventListeners.find(id);

	if (fi == _eventListeners.end()) 
	{
		//We create a new list of delegate for this particular event
		_eventListeners[id] = std::list<EventDelegate>();
	}

	auto& list = _eventListeners[id];
	list.push_back(proc);
	return true;
}

bool EventManager::RemoveListener(IEventData::id_t id, EventDelegate proc)
{
	auto j = _eventListeners.find(id);
	if (j == _eventListeners.end())
	{
		return false;
	}

	auto& list = j->second; //The delegate stored
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		EventDelegate& func = *i;
		if (func.target<EventDelegate>() == proc.target<EventDelegate>())
		{
			list.erase(i);
			return true;
		}
	}
	return false;
}

void EventManager::QueueEvent(IEventDataPtr ev)
{
	_eventQueue.push_back(ev);
}

void EventManager::ProcessEvents()
{
	size_t count = _eventQueue.size();

	if (count)
	{
		LOG("EventManager : {} events during frame {} ", count, gFrame - 1);

		for (auto& it : _eventQueue)
		{
			auto listeners = _eventListeners.find(it->GetID()); //We want all the listeners who registered to this particular event

			if (listeners != _eventListeners.end())
			{
				for (auto listener : listeners->second)
				{
					listener(it); // Trigger the delegate and pass the event
				}
			}
		}
		_eventQueue.clear();
	}
}

EventListener::~EventListener()
{
	for (auto i : _localEvents)
	{
		gEventManager.RemoveListener(i.first, i.second);
	}
}

bool EventListener::OnEvent(IEventData::id_t id, EventDelegate proc)
{
	if (gEventManager.AddListener(id, proc))
	{
		_localEvents.push_back(EventPair(id, proc));
	}
	else
	{
		return false;
	}
	return true;
}
