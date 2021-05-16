#pragma once

#include "gl/core/size.hpp"
#include "gl/core/coordinates.hpp"

#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace gl {
	class window {
	public:
		window();
		window(std::string, size);
		~window();

	public:
		inline std::string get_title() { return this->title; };
		inline size get_size() { return this->sz; };
		inline bool get_resize() { return this->resize; };

		void set_title(std::string title) { this->title = title; };
		void set_size(size sz) { this->sz = sz; };
		void set_resize(bool resize) { this->resize = resize; };

	public:
		void clear();
		void scale(coordinates);
		void rotate(float, bool, bool, bool);
		void translate(float, float, float);

	public:
		bool is_action();

	public:
		void show();
		void close();
		void update();

	public:
		float get_time();
		bool is_pressed(char);

	private:
		std::string title;
		size sz;
		bool resize;

		GLFWwindow *win;
	};
};
