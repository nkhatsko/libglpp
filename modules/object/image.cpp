#include "gl/object/image.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


using namespace gl;

void image::draw() {
	/* load */
	int w, h, c;
	unsigned char *data = stbi_load(this->path.c_str(), &w, &h, &c, 0);

	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		c == 3 ? GL_RGB : GL_RGBA,
		w,
		h,
		0,
		c == 3 ? GL_RGB : GL_RGBA,
		GL_UNSIGNED_BYTE,
		data
	);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_image_free(data);

	/* show */
	glEnable(GL_TEXTURE_2D);

	glColor4f(this->cl.get_red(), this->cl.get_green(), this->cl.get_blue(), this->cl.get_alpha());
	glBegin(GL_QUADS);
		glTexCoord2d(0, 1);
		glVertex2d(this->cd.get_x() + this->sz.get_width(), this->cd.get_y() - this->sz.get_height());

		glTexCoord2d(1, 1);
		glVertex2d(this->cd.get_x(), this->cd.get_y() - this->sz.get_height());

		glTexCoord2d(1, 0);	
		glVertex2d(this->cd.get_x(), this->cd.get_y());

		glTexCoord2d(0, 0);
		glVertex2d(this->cd.get_x() + this->sz.get_width(), this->cd.get_y());
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);
};
