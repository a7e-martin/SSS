#ifndef DEF_GLPROGRAM_H
#define DEF_GLPROGRAM_H
#include <string>

typedef unsigned int GLuint;

class GlProgram {
public:
	GlProgram(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint GetID() const;
private:
	GLuint _id;
};

#endif
