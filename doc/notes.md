# The purpose of this file is to serve as a guide to use the CMakeList.txt while further working on this project.

## Following is the original code in the CMakeList.txt file in the ../build directory.

-Any changes done will be made through this takedn as example.

```
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/../src/*.cpp)

add_executable(test ../src/test.cpp ${SRC_FILES} )

target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
```


## To include some static libraries in CMakeList.txt in ../build directory

```target_include_directories( lib_name PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib_name/include) ```

### Adding this library

```
target_link_libraries(test PUBLIC lib_name)
```
