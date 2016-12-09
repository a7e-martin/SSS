#ifndef DEF_RENDERERCOMPONENT_H
#define DEF_RENDERERCOMPONENT_H
#include "component.h"
#include "material.h"
#include "sprite.h"

class Renderer;

class RendererComponent : public Component{
public:
    void Init();
    Sprite* GetSprite();
    unsigned char GetLayer();
	void Render();
private:
    Sprite _sprite;
    unsigned char _layer;
    Material* _material; //Ptr to allow many entities to use the same material thus the same shader
	Renderer* _renderer;
};

#endif