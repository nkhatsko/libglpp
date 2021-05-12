#pragma once

#include "color.hpp"
#include "coordinates.hpp"
#include "object.hpp"

#include <list>
#include <memory>
#include <initializer_list>


namespace gl {
	class polygon : public object {
	public:
		polygon() : items() {};
		polygon(std::initializer_list<std::pair<color, coordinates>> i) :
			items(i) {};

	public:
		inline int size() { return this->items.size(); };

		void push_front(std::pair<color, coordinates>);
		void push_back(std::pair<color, coordinates>);
		void push(int, std::pair<color, coordinates>);

		void pop_front();
		void pop_back();
		void pop(int);

		std::pair<color, coordinates> & front();
		std::pair<color, coordinates> & back();
		std::pair<color, coordinates> & at(int);

	public:
		void draw() override;

	private:
		std::list<std::pair<color, coordinates>> items;
	};
};
