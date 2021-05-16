#include <iostream>
#include <cmath>

#include <gl/gl.hpp>


int main() {
	gl::window w;
	w.set_title("circle");
	w.set_size(gl::size(512, 512));
	w.set_resize(false);
	w.show();

	gl::polygon p;
	for (float i = -3; i <= 3; i += 0.1) {
		p.push_back({
			gl::color(1.0, 1.0, 1.0),
			gl::coordinates(std::cos(i), std::sin(i))
		});
	};

	w.scale(gl::coordinates(0.5, 0.5, 0.5));
	while (w.is_action()) {
		w.clear();
		w.rotate(1, true, false, false);

		p.draw();

		if (w.is_pressed('Q')) {
			break;
		};

		w.update();
	};

	return 0;
};
