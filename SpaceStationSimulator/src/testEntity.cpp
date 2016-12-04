#include "testEntity.h"
#include "rendererComponent.h"

TestEntity::TestEntity() {
    RendererComponent* r = AddComponent<RendererComponent>();

}