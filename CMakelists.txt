cmake_minimum_required(VERSION 3.6)

add_subdirectory(color)
add_subdirectory(bmp)
add_subdirectory(bmpc)
add_subdirectory(dispcolor)

project(test)

#add_executable(${PROJECT_NAME} examples/one-frame.c)
#add_executable(${PROJECT_NAME} examples/multi-frame.c)
#add_executable(${PROJECT_NAME} examples/animated.c)
add_executable(${PROJECT_NAME} examples/test-dispcolor.c)

target_link_libraries(${PROJECT_NAME} bmpc color dispcolor)
include_directories(bmpc color dispcolor dispcolor/fonts)
