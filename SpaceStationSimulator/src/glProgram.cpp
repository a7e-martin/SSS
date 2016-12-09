#include "glProgram.h"
#include "gvars.h"
#include "shader.h"
#include "resourceManager.h"

GlProgram::GlProgram(const std::string & vertexShader, const std::string & fragmentShader)
{
	Shader* vertex = gResourceManager.AddResource<Shader>(vertexShader);
	Shader* fragment = gResourceManager.AddResource<Shader>(fragmentShader);

	if (vertex && fragment)
	{
		//_id = glCreateProgram();

	}
}

GLuint GlProgram::GetID() const
{
	return _id;
}
