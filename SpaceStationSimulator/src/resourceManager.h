#ifndef DEF_RESOURCEMANAGER_H
#define DEF_RESOURCEMANAGER_H
#include <map>

typedef enum{
    RESOURCE_NULL = 0,
    RESOURCE_GRAPHIC = 1,
    RESOURCE_AUDIO = 2,
}RESOURCE_TYPE;

class Resource{
public:
    Resource() : _id(0), _type(RESOURCE_NULL){}
    virtual ~Resource() {};
    virtual void Load() = 0;
    virtual void Unload() = 0;

    void SetId(unsigned int id){_id = id;};
    unsigned int GetId() {return _id;};

    void SetFilename(std::string filename) {_filename = filename;}
    std::string GetFilename() {return _filename;}

    void SetResourceType(RESOURCE_TYPE type) {_type = type;}
    RESOURCE_TYPE GetResourceType(){return _type;}

    bool IsLoaded() {return _loaded;}
    void SetLoaded(bool value){_loaded = value;}
private:
    std::string _filename;
    RESOURCE_TYPE _type;
    unsigned int _id;
    bool _loaded;
};

class ResourceManager{
public:
    void Load();
    Resource* GetResource(unsigned int id);
private:
    std::map<unsigned int, Resource> _resources;

};

#endif