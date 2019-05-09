#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>

#include <utils/logging/logging.h>
#include <graphics/incl/shader_loader.h>
#include <graphics/incl/model.h>

const int window_width = 1280;
const int window_height = 800;

// number of subsamples per pixel
const int samples = 4;

glm::vec3 cam_pos(0.0f, 5.0f, 20.0f);		// e  | Position of camera
glm::vec3 cam_look_at(0.0f, 0.0f, 0.0f);	// d  | This is where the camera looks at
glm::vec3 cam_up(0.0f, 1.0f, 0.0f);			// up | What orientation "up" is

glm::mat4 projection;
glm::mat4 view;

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
        LOG.error("Failed to Create OpenGL Context");
		return mWindow;
	}

	// Create Context and Load OpenGL Functions
	glfwMakeContextCurrent(mWindow);
	gladLoadGL();
    LOG.info("OpenGL {}\n", glGetString(GL_VERSION));

	return mWindow;
}

int main(int argc, char * argv[]) {
    InitLogger("ClientLogger");

	auto mWindow = WindowSetup();

	glfwSetKeyCallback(mWindow, key_callback);
	glfwSetMouseButtonCallback(mWindow, mouse_click_callback);

    ShaderLoader loader;

    projection = glm::perspective(45.0f, (float)window_width / (float)window_height, 0.1f, 1000.0f);
    view = glm::lookAt(cam_pos, cam_look_at, cam_up);

    Model m(loader, "../models/cube/cube.obj", "../src/graphics/shaders/playershader.vert", "../src/graphics/shaders/playershader.frag");

	// Rendering Loop
	while (glfwWindowShouldClose(mWindow) == false) {
		if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(mWindow, true);

		// Background Fill Color
		glClearColor(1.00f, 0.25f, 0.25f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

        m.Render(view, projection);

		// Flip Buffers and Draw
		glfwSwapBuffers(mWindow);
		glfwPollEvents();
	}   
    
    LOG.flush();

    glfwTerminate();

	return 0;
}