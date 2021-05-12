#include "gl/window.hpp"


using namespace gl;

window::window() : title(), sz(), resize() {
	if (!glfwInit()) {
		throw "error: glfwInit";
	};
	this->win = nullptr;
};

window::window(std::string title, size sz) : window() {
	this->title = title;
	this->sz = sz;
};

window::~window() {
	this->close();
};

void window::clear() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);
};

void window::scale(coordinates cd) {
	glScalef(cd.get_x(), cd.get_y(), cd.get_z());
};

void window::rotate(float deg, bool is_x, bool is_y, bool is_z) {
	glRotatef(deg, is_x, is_y, is_z);
};

void window::translate(float x, float y, float z) {
	glTranslatef(x, y, z);
};

bool window::is_action() {
	int w, h;
	glfwGetFramebufferSize(this->win, &w, &h);
	glViewport(0, 0, w, h);

	return !glfwWindowShouldClose(this->win);
};

void window::show() {
	/* window setup */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, this->resize);

	/* create window */
	this->win = glfwCreateWindow(this->sz.get_width(), this->sz.get_height(), title.c_str(), nullptr, nullptr);
	if (!this->win) {
		throw "error: glfwCreateWindow";
	};
	glfwMakeContextCurrent(this->win);

	/* enable alpha color */
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
};

void window::close() {
	/* glfwSetWindowShouldClose(this->win, GLFW_TRUE); */
	glfwDestroyWindow(this->win);
	glfwTerminate();
};

void window::update() {
	glfwPollEvents();
	glfwSwapBuffers(this->win);
};

float window::get_time() {
	return glfwGetTime();
};

bool window::is_pressed(char key) {
	return glfwGetKey(this->win, key) == GLFW_PRESS;
};
