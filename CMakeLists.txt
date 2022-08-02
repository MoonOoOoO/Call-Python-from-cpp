cmake_minimum_required(VERSION 3.10)

project(main VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_executable(main main.cc)

# https://cmake.org/cmake/help/latest/module/FindPython3.html
find_package(Python3 COMPONENTS Development Interpreter)
IF (Python3_FOUND)
    INCLUDE_DIRECTORIES(${Python3_INCLUDE_DIRS})
    # INCLUDE_DIRECTORIES(${Python3_EXECUTABLE})
ENDIF()

target_link_libraries(main PUBLIC ${Python3_LIBRARIES})

# cmake_print_variables(${Python3_LIBRARIES})
# cmake_print_variables(${Python3_INCLUDE_DIRS})
# cmake_print_variables(${Python3_EXECUTABLE})
# cmake_print_variables(${CMAKE_CURRENT_SOURCE_DIR})
