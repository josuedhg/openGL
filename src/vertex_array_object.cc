#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

float vertices[] =
{
	-0.5f, -0.5f, 0.0f, // bottom left
	0.5f, -0.5f, 0.0f, // bottom right
	0.0f, 0.5f, 0.0f // top center
};

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

	unsigned int VBO; // vertex buffer object
	unsigned int VAO; // vertex array object
	
	glGenBuffers(1, &VBO); // generate 1 buffer
	glGenVertexArrays(1, &VAO); // generate 1 vertex array
	
	glBindVertexArray(VAO); // bind vertex array
	glBindBuffer(GL_ARRAY_BUFFER, VBO); // bind buffer to array buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // copy vertices to buffer
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0); // set vertex attributes
	glEnableVertexAttribArray(0); // enable vertex attribute

	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); // set color
		glClear(GL_COLOR_BUFFER_BIT); // clear color buffer

		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // set polygon mode
		glBindVertexArray(VAO); // bind vertex array
		glDrawArrays(GL_TRIANGLES, 0, 3); // draw triangle

		glfwSwapBuffers(window); // display
		glfwPollEvents(); // poll Events
	}
	
	glfwDestroyWindow(window); // destroy window
	glfwTerminate(); // terminate GLFW
	return 0;
}
