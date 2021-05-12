#pragma once

#include "size.hpp"
#include "color.hpp"
#include "coordinates.hpp"
#include "object.hpp"

#include <string>


namespace gl {
	class image : public object {
	public:
		image() : sz(), cl(), cd(), path() {};

		image(size a, color b, coordinates c, std::string d) :
			sz(a), cl(b), cd(c), path(d) {};

	public:
		inline size get_size() { return this->sz; };
		inline color get_color() { return this->cl; };
		inline coordinates get_coordinates() { return this->cd; };
		inline std::string get_path() { return this->path; };

		void set_size(size sz) { this->sz = sz; };
		void set_color(color cl) { this->cl = cl; };
		void set_coordinates(coordinates cd) { this->cd = cd; };
		void set_path(std::string path) { this->path = path; };

	public:
		void draw() override;

	private:
		size sz;
		color cl;
		coordinates cd;
		std::string path;
	};
};
