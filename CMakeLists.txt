cmake_minimum_required(VERSION 3.18)

project(cpp-template)
set( CMAKE_CXX_FLAGS "-g -Wall -Wl,--no-as-needed -ldl" )

include(CTest)
include(GNUInstallDirs)
include(CMakeOptions.txt)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)

add_subdirectory(src)

message(STATUS "GLFW " ${GLFW_LIBRARIES})
message(STATUS "GLEW " ${GLEW_LIBRARIES})
message(STATUS "OPENGL " ${OPENGL_LIBRARIES})
