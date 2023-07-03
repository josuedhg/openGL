#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
	glfwInit(); // initialize GLFW
	
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

		glBegin(GL_TRIANGLES); // draw triangle
		glVertex3f(-0.5f, -0.5f, 0.0f); // left
		glVertex3f(0.5f, -0.5f, 0.0f); // right
		glVertex3f(0.0f, 0.5f, 0.0f); // top
		glEnd();

		glfwSwapBuffers(window); // display
		glfwPollEvents(); // poll Events
	}
	
	glfwDestroyWindow(window); // destroy window
	glfwTerminate(); // terminate GLFW
	return 0;
}
