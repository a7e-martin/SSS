#ifndef DEF_MATERIAL_H
#define DEF_MATERIAL_H
#include "shader.h"

class Material{
public:
    Shader* GetShader();
private:
    Shader _shader;
};

#endif