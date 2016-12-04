#ifndef DEF_EVENTMANAGER_H
#define DEF_EVENTMANAGER_H
#include <map>
#include <vector>
#include <memory>
#include <list>
#include <functional>

class IEventData {
public:
	typedef size_t id_t;
	virtual id_t GetID() = 0;
};

typedef std::shared_ptr<IEventData> IEventDataPtr;
typedef std::function<void(IEventDataPtr&)> EventDelegate;

class IEventManager {
public:
	virtual bool AddListener(IEventData::id_t id, EventDelegate proc) = 0;
	virtual bool RemoveListener(IEventData::id_t id, EventDelegate proc) = 0;
	virtual void QueueEvent(IEventDataPtr ev) = 0;
	virtual void ProcessEvents() = 0;
};

//DECLARE_EVENT will create the static function and the GetID() function where it is called
#define DECLARE_EVENT(type) \
	static IEventData::id_t ID() {\
		return reinterpret_cast<IEventData::id_t>(&ID);/*Returns the adress of the static function ID() (where it will be added when calling DECLARE_EVENT) */ \
	} \
	IEventData::id_t GetID() override { \
		return ID(); \
	}

class EventManager : public IEventManager {
public:
	typedef std::list<EventDelegate> EventDelegateList;

	virtual bool AddListener(IEventData::id_t id, EventDelegate proc) override;
	virtual bool RemoveListener(IEventData::id_t id, EventDelegate proc) override;
	virtual void QueueEvent(IEventDataPtr ev) override;
	virtual void ProcessEvents() override;
private:
	std::list<std::shared_ptr<IEventData>> _eventQueue;
	std::map<IEventData::id_t, EventDelegateList> _eventListeners;
};

class EventListener {
public:
	template<typename T> bool OnEvent(std::function<void(std::shared_ptr<T>)> proc) {
		return OnEvent(T::ID(), [&, proc](IEventDataPtr data) {
			auto ev = std::dynamic_pointer_cast<T>(data);
			if (ev) proc(ev);
		});
	}

protected:
	typedef std::pair<IEventData::id_t, EventDelegate> EventPair;
	virtual ~EventListener();
	bool OnEvent(IEventData::id_t id, EventDelegate proc);

private:
	std::vector<EventPair> _localEvents;
};


#endif