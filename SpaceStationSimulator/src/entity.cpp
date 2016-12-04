#include "entity.h"
#include <iostream>

Entity::Entity()
{
	ThrowEvent(new NewEntityEvent(this));
}
