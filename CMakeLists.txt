cmake_minimum_required(VERSION 3.0)
project(shakeit)

# setting
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set (SRC_FILES src/image_effects.cpp src/main.cpp)

# output
add_executable(shakeit ${SRC_FILES})

# custom commands

# custom targets
add_custom_target(run DEPENDS shakeit
    COMMAND ./shakeit -i test_images/mad.png -o shaking_mad.gif -r 50 -n 8 -t 20
    COMMAND xdg-open shaking_mad.gif)

#definitions
add_definitions( -DMAGICKCORE_QUANTUM_DEPTH=16 )
add_definitions( -DMAGICKCORE_HDRI_ENABLE=0 )

# libraries
find_package(ImageMagick COMPONENTS MagickCore)
find_package(ImageMagick COMPONENTS Magick++)
include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(shakeit ${ImageMagick_LIBRARIES})