cmake_minimum_required(VERSION 3.27)
project(rubik_kubik)

set(CMAKE_CXX_STANDARD 17)

find_package(GLU REQUIRED)
include_directories(${GLU_INCLUDE_DIRS})

add_executable(rubik_kubik main.cpp
        Component.cpp
        Component.h
        Cube.cpp
        Cube.h
        Solver.cpp
        Solver.h)

target_link_libraries(rubik_kubik ${GL_LIBRARIES})
target_link_libraries(rubik_kubik ${GLU_LIBRARY})
target_link_libraries(rubik_kubik ${GLUT_LIBRARIES})
target_link_libraries(rubik_kubik -lopengl32 -g -lfreeglut)
