#ifndef DEF_SHADER_H
#define DEF_SHADER_H
#include "resourceManager.h"

class Shader : public Resource{
public:
	virtual void Load() override;
	virtual void Unload() override;
private:

};

#endif