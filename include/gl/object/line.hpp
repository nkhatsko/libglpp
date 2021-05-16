#pragma once

#include "gl/core/color.hpp"
#include "gl/core/coordinates.hpp"
#include "gl/core/object.hpp"

#include <list>
#include <memory>
#include <initializer_list>


namespace gl {
	class line : public object {
	public:
		line() : width(), items() {};
		line(int w, std::initializer_list<std::pair<color, coordinates>> i) :
			width(w), items(i) {};

	public:
		inline int get_width() { return this->width; };
		void set_width(int width) { this->width = width; };

	public:
		inline int size() { return this->items.size(); };

		void push_front(std::pair<color, coordinates> cc);
		void push_back(std::pair<color, coordinates> cc);
		void push(int index, std::pair<color, coordinates> cc);

		void pop_front();
		void pop_back();
		void pop(int);

		std::pair<color, coordinates> & front();
		std::pair<color, coordinates> & back();
		std::pair<color, coordinates> & at(int);

	public:
		void draw() override;

	private:
		int width;
		std::list<std::pair<color, coordinates>> items;
	};
};
