#include "gl/object/polygon.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>


using namespace gl;

void polygon::push_front(std::pair<color, coordinates> cc) {
	this->items.push_front(cc);
};

void polygon::push_back(std::pair<color, coordinates> cc) {
	this->items.push_back(cc);
};

void polygon::push(int index, std::pair<color, coordinates> cc) {
	// this->items.insert(std::advance(this->items.begin(), index), cc);
};

void polygon::pop_front() {
	this->items.erase(this->items.begin());
};

void polygon::pop_back() {
	this->items.erase(std::prev(this->items.end()));
};

void polygon::pop(int index) {
	auto it = this->items.begin();
	std::advance(it, index);
	this->items.erase(it);
};

std::pair<color, coordinates> & polygon::front() {
	return (*this->items.begin());
};

std::pair<color, coordinates> & polygon::back() {
	return (*std::prev(this->items.end()));
};

std::pair<color, coordinates> & polygon::at(int index) {
	auto it = this->items.begin();
	std::advance(it, index);
	return (*it);
};

void polygon::draw() {
	glBegin(GL_POLYGON);
	for (auto item : this->items) {
		glColor4f(item.first.get_red(), item.first.get_green(), item.first.get_blue(), item.first.get_alpha());
		glVertex3f(item.second.get_x(), item.second.get_y(), item.second.get_z());
	};
	glEnd();
};
