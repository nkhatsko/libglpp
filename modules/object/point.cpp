#include "gl/object/point.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace gl;

void point::draw() {
	glPointSize(this->size);
	glColor4f(this->cl.get_red(), this->cl.get_green(), this->cl.get_blue(), this->cl.get_alpha());

	glBegin(GL_POINTS);
		glVertex3f(this->cd.get_x(), this->cd.get_y(), this->cd.get_z());
		glVertex3f(this->cd.get_x() + 0.5, this->cd.get_y(), this->cd.get_z());
	glEnd();
};
