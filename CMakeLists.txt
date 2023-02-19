#make_minimum_required(VERSION 3.14)

# add_executable(program src/main.cpp src/MathObjects/vector.h src/MathObjects/vector.cpp src/MathObjects/utils.h)
#add_executable(program SOURCE_DIR /src)

cmake_minimum_required(VERSION 3.14)
project(Render)

# Set the source files for the executable
set(SOURCES
    src/main.cpp
    src/MathObjects/vector.h
    src/MathObjects/vector.cpp
    src/MathObjects/ray.h
    src/MathObjects/ray.cpp
    src/RenderObjects/objects.h
    src/RenderObjects/objects.cpp
)
# Add the executable
add_executable(program ${SOURCES})
