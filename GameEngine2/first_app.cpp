#include "first_app.hpp"
#include "lve_window.hpp"

namespace lve {

	void FirstApp::run() {
		while (!lveWindow.shouldClose()) {
			glfwPollEvents();//key for closing

		}

	}
} //namespace lve