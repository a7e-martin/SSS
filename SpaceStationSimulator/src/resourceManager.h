#ifndef DEF_RESOURCEMANAGER_H
#define DEF_RESOURCEMANAGER_H
#include <map>
#include <memory>
#include <string>

#include <typeindex>
#include <iostream>
#include "resource.h"
#include "format.h"

class ResourceManager{
public:
    void Load();
    Resource* GetResource(unsigned int id);

	template<typename T> T* AddResource(std::string name) {
		if (_resources.find(name) != _resources.end())
		{
			return static_cast<T*>(_resources[name].get());
		}
		else
		{
			_resources[name] = std::make_unique<T>();
			T* resource = static_cast<T*>(_resources[name].get());
			resource->Load();
			resource->SetName(name);
			std::cout << fmt::format("Resource {} loaded\n", name);
			return resource;
		}
	}
private:
	//The key is the name of the file
    std::map<std::string, std::unique_ptr<Resource>> _resources;

};

#endif