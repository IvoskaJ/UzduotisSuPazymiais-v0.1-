# CMakeList.txt : CMake project for student v1.0, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("student v1.0")

# Add source to this project's executable.
add_executable (generateFiles "generateFiles.cpp")
add_executable (vector1  "Studentas.h"  "vector1.cpp"  "vector1.h")
add_executable (vector2  "Studentas.h"  "vector2.cpp"  "vector2.h")
add_executable (deque1  "Studentas.h"  "deque1.cpp"  "deque1.h")
add_executable (deque2  "Studentas.h"  "deque2.cpp"  "deque2.h")
add_executable (list1  "Studentas.h"  "list1.cpp"  "list1.h")
add_executable (list2  "Studentas.h"  "list2.cpp"  "list2.h")

# TODO: Add tests and install targets if needed.
