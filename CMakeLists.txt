cmake_minimum_required(VERSION 3.0.0)
project(functional_ds LANGUAGES CXX)
add_subdirectory(src)
add_subdirectory(tests)
# ../dependencies/valgrind/bin/valgrind --leak-check=full ./brouhaha
