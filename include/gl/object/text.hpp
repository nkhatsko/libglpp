#pragma once

#include "gl/core/coordinates.hpp"
#include "gl/core/object.hpp"

#include <string>


namespace gl {
	class text : public object {
	public:
		text() : size(), cd(), font(), str() {};
		text(int a, coordinates b, std::string c, std::string d) :
			size(a), cd(b), font(c), str(d) {};

	public:
		inline int get_size() { return this->size; };
		inline coordinates get_coordinates() { return this->cd; };
		inline std::string get_font() { return this->font; };
		inline std::string get_str() { return this->str; };

		void set_size(int size) { this->size = size; };
		void set_coordinates(coordinates cd) { this->cd = cd; };
		void set_font(std::string font) { this->font = font; };
		void set_str(std::string str) { this->str = str; };

	public:
		void draw() override;

	private:
		int size;
		coordinates cd;
		std::string font;
		std::string str;
	};
};
