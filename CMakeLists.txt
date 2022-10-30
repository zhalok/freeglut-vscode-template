cmake_minimum_required(VERSION 3.23)
project(GLUT_)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLUT_ main.cpp)
target_link_libraries(GLUT_ -lglut -lglfw -lGLEW -lGL -lGLU)

