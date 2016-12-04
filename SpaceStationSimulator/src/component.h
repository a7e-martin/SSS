#ifndef DEF_COMPONENT_H
#define DEF_COMPONENT_H
#include "entity.h"

class Entity;

class Component{
public:
    void SetParent(Entity* entity);
private:
    Entity* _parent;
};


#endif