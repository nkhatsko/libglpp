#pragma once


namespace gl {
	class color {
	public:
		color() : color(1, 1, 1) {};

		color(float red, float green, float blue) : color(red, green, blue, 1) {};

		color(float red, float green, float blue, float alpha) {
			this->set(red, green, blue, alpha);
		};

	public:
		inline float get_red() { return (this->red); };
		inline float get_green() { return (this->green); };
		inline float get_blue() { return (this->blue); };
		inline float get_alpha() { return (this->alpha); };

		void set_red(float red) { this->red = red; };
		void set_green(float green) { this->green = green; };
		void set_blue(float blue) { this->blue = blue; };
		void set_alpha(float alpha) { this->alpha = alpha; };

		void set(float red, float green, float blue, float alpha) {
			this->red = red;
			this->green = green;
			this->blue = blue;
			this->alpha = alpha;
		};

	private:
		float red;
		float green;
		float blue;
		float alpha;
	};
};
