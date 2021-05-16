#include "gl/object/line.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace gl;

void line::push_front(std::pair<color, coordinates> cc) {
	this->items.push_front(cc);
};

void line::push_back(std::pair<color, coordinates> cc) {
	this->items.push_back(cc);
};

void line::push(int index, std::pair<color, coordinates> cc) {
	auto it = this->items.begin();
	std::advance(it, index);
	this->items.insert(it, cc);
};

void line::pop_front() {
	this->items.erase(this->items.begin());
};

void line::pop_back() {
	this->items.erase(std::prev(this->items.end()));
};

void line::pop(int index) {
	auto it = this->items.begin();
	std::advance(it, index);
	this->items.erase(it);
};

std::pair<color, coordinates> & line::front() {
	return (*this->items.begin());
};

std::pair<color, coordinates> & line::back() {
	return (*std::prev(this->items.end()));
};

std::pair<color, coordinates> & line::at(int index) {
	auto it = this->items.begin();
	std::advance(it, index);
	return (*it);
};

void line::draw() {
	glLineWidth(this->width);

	glBegin(GL_LINE_LOOP);
	for (auto item : this->items) {
		glColor4f(item.first.get_red(), item.first.get_green(), item.first.get_blue(), item.first.get_alpha());
		glVertex3f(item.second.get_x(), item.second.get_y(), item.second.get_z());
	};
	glEnd();
};
