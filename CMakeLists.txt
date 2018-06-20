cmake_minimum_required(VERSION 3.0)
project(shake_it)

# setting
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -std=c99")
set (SRC_FILES src/main.cpp)

# output
add_executable(shakeit ${SRC_FILES})

#definitions
add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )

# libraries
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(shakeit ${ImageMagick_LIBRARIES})