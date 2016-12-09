#ifndef DEF_RESOURCE_H
#define DEF_RESOURCE_H
#include <string>

class Resource {
public:
	virtual ~Resource() {};
	virtual void Load() = 0;
	virtual void Unload() = 0;

	void SetName(std::string name) { _name = name; };
	std::string GetName() { return _name; };
	bool IsLoaded() { return _loaded; }
	void SetLoaded(bool value) { _loaded = value; }
private:
	unsigned int _id;
	bool _loaded;
	std::string _name;
};

#endif