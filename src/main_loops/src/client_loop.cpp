#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include <graphics/incl/shader_loader.h>

const int window_width = 1280;
const int window_height = 800;

// number of subsamples per pixel
const int samples = 4;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		std::cout << "test" << std::endl;
	}
}
void mouse_click_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS) {
		std::cout << "mouse pressed" << std::endl;
	}
}

auto WindowSetup() {
	// Load GLFW and Create a Window
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	if (samples > 1) glfwWindowHint(GLFW_SAMPLES, samples);
	auto mWindow = glfwCreateWindow(window_width, window_height, "game", nullptr, nullptr);

	// Check for Valid Context
	if (mWindow == nullptr) {
		std::cerr << "Failed to Create OpenGL Context" << std::endl;
		return mWindow;
	}

	// Create Context and Load OpenGL Functions
	glfwMakeContextCurrent(mWindow);
	gladLoadGL();
	std::cout << "OpenGL {}\n" << glGetString(GL_VERSION) << std::endl;

	return mWindow;
}

int main(int argc, char * argv[]) {
	auto mWindow = WindowSetup();

	glfwSetKeyCallback(mWindow, key_callback);
	glfwSetMouseButtonCallback(mWindow, mouse_click_callback);

    ShaderLoader loader;
    //loader.LoadShader("C:/Users/cocoa/Documents/game/src/graphics/shaders/playershader.vert", "C:/Users/cocoa/Documents/game/src/graphics/shaders/playershader.frag");
    loader.LoadShader("../src/graphics/shaders/playershader.vert", "../src/graphics/shaders/playershader.frag");

	// Rendering Loop
	while (glfwWindowShouldClose(mWindow) == false) {
		if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(mWindow, true);

		// Background Fill Color
		glClearColor(1.00f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Flip Buffers and Draw
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}   glfwTerminate();

	return 0;
}