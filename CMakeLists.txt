#make_minimum_required(VERSION 3.14)

# add_executable(program src/main.cpp src/MathObjects/vector.h src/MathObjects/vector.cpp src/MathObjects/utils.h)
#add_executable(program SOURCE_DIR /src)

cmake_minimum_required(VERSION 3.14)
project(Render)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)

# Set the source files for the executable
set(SOURCES
    src/main.cpp
    src/MathObjects/vector.h
    src/MathObjects/vector.cpp
    src/MathObjects/ray.h
    src/MathObjects/ray.cpp
    src/RenderObjects/objects.h
    src/RenderObjects/objects.cpp
    src/RenderObjects/renderController.h
    src/RenderObjects/renderController.cpp
)
# Add the executable
add_executable(program ${SOURCES})

set(SFML_DIR "./sfml/lib/cmake/SFML")

target_link_libraries(program sfml-graphics)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
# graphics audio window system
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)