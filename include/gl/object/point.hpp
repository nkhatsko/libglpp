#pragma once

#include "gl/core/color.hpp"
#include "gl/core/coordinates.hpp"
#include "gl/core/object.hpp"


namespace gl {
	class point : public object {
	public:
		point() : size(), cl(), cd() {};
		point(int a, color b, coordinates c) :
			size(a), cl(b), cd(c) {};

	public:
		inline int get_size() { return this->size; };
		inline color get_color() { return this->cl; };
		inline coordinates get_coordinates() { return this->cd; };

		void set_size(int size) { this->size = size; };
		void set_color(color cl) { this->cl = cl; };
		void set_coordinates(coordinates cd) { this->cd = cd; };

	public:
		void draw() override;

	private:
		int size;
		color cl;
		coordinates cd;
	};
};
