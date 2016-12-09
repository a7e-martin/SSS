#ifndef DEF_GVARS_H
#define DEF_GVARS_H
#include "eventManager.h"
#include "inputEventManager.h"
#include "resourceManager.h"

extern int gFrame;
extern EventManager gEventManager;
extern InputEventManager gInputEventManager;
extern ResourceManager gResourceManager;

#define ThrowEvent(x) gEventManager.QueueEvent(IEventDataPtr(x));

#endif