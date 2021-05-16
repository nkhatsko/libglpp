#pragma once


namespace gl {
	class size {
	public:
		size() : size(0, 0) {};

		size(float width, float height) : size(width, height, 1) {};

		size(float width, float height, float length) {
			this->set(width, height, length);
		};

	public:
		inline float get_width() { return (this->width); };
		inline float get_height() { return (this->height); };
		inline float get_length() { return (this->length); };

		void set_width(float width) { this->width = width; };
		void set_height(float height) { this->height = height; };
		void set_length(float length) { this->length = length; };

		void set(float width, float height, float length) {
			this->width = width;
			this->height = height;
			this->length = length;
		};

	private:
		float width;
		float height;
		float length;
	};
};
