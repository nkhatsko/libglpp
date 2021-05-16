#pragma once


namespace gl {
	class coordinates {
	public:
		coordinates() : coordinates(0, 0) {};

		coordinates(float x, float y) : coordinates(x, y, 0) {};

		coordinates(float x, float y, float z) {
			this->set(x, y, z);
		};

	public:
		inline float get_x() { return (this->x); };
		inline float get_y() { return (this->y); };
		inline float get_z() { return (this->z); };

		void set_x(float x) { this->x = x; };
		void set_y(float y) { this->y = y; };
		void set_z(float z) { this->z = z; };

		void set(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		};

	private:
		float x;
		float y;
		float z;
	};
};
