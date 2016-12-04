#ifndef DEF_GVARS_H
#define DEF_GVARS_H
#include "eventManager.h"
#include "inputEventManager.h"

extern int gFrame;
extern EventManager gEventManager;
extern InputEventManager gInputEventManager;

#define ThrowEvent(x) gEventManager.QueueEvent(IEventDataPtr(x));

#endif