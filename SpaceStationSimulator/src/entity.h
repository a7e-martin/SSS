#ifndef DEF_ENTITY_H
#define DEF_ENTITY_H

#include <typeindex>
#include "eventManager.h"
#include "gvars.h"
#include "component.h"

class Component;

class Entity : public EventListener{
public:
	template<typename T> T* AddComponent();
	template<typename T> T* GetComponent();
	Entity();
	//template<typename T>
	//T* AddEntity();

private:
	std::map<std::type_index, std::unique_ptr<Component>> _components;
};

class NewEntityEvent : public IEventData {
public:
	DECLARE_EVENT(NewEntityEvent); //This will add the static function ID() and the GetID() function as seen in eventManager.h

	NewEntityEvent(Entity* entity) {
		m_entity = entity;
	}

	Entity* GetEntity() {
		return m_entity;
	}

private:
	Entity* m_entity;
};

template<typename T>
T* Entity::AddComponent(){
	std::type_index index = std::type_index(typeid(T));
	_components[index] = std::make_unique<T>();
	T* component = static_cast<T*>(_components[index].get());
	component->SetParent(this);
	return component;
}

template<typename T>
T* Entity::GetComponent(){
	std::type_index index = std::type_index(typeid(T));
	if(_components.find(index) != _components.end())
		return static_cast<T*>(_components.at(index).get());
	else
		return nullptr;
}

//template<typename T>
//T* Entity::AddEntity()
//{
//	T* entity = new T();
//	ThrowEvent(new NewEntityEvent(entity));
//	return entity;
//}
#endif