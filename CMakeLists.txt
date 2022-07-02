cmake_minimum_required(VERSION 3.13)  # CMake version check
project(container_templates)               # Create project "container_templates"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp ds.cpp algorithms.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})

target_include_directories(main
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/inc
)
