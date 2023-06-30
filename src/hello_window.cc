#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	glfwInit(); // initialize GLFW
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // set major version to 3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // set minor version to 3
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // set profile to core profile
	
	GLFWwindow *window = glfwCreateWindow(1000, 800, "OpenGL 3.3", NULL, NULL); // create window
	if (!window) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate(); // terminate GLFW
		return -1;
	}

	glfwMakeContextCurrent(window); // make the window the current context

	if (glewInit() != GLEW_OK) { // initialize GLEW
		std::cerr << "Failed to initialize GLEW" << std::endl;
		glfwTerminate(); // terminate GLFW
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // set color
		glClear(GL_COLOR_BUFFER_BIT); // clear color buffer
		glfwSwapBuffers(window); // display
		glfwPollEvents(); // poll Events
	}
	
	glfwDestroyWindow(window); // destroy window
	glfwTerminate(); // terminate GLFW
	return 0;
}
