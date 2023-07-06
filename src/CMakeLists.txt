add_executable(hello_window hello_window.cc)
target_link_libraries(hello_window glfw OpenGL GLEW)

add_executable(hello_classic_opengl hello_classic_opengl.cc)
target_link_libraries(hello_classic_opengl glfw OpenGL GLEW)

add_executable(vertex_array_object vertex_array_object.cc)
target_link_libraries(vertex_array_object glfw OpenGL GLEW)
