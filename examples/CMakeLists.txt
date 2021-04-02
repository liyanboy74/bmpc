cmake_minimum_required(VERSION 3.6)

project(test-bmpc)

add_executable(${PROJECT_NAME} one-frame.c)
#add_executable(${PROJECT_NAME} multi-frame.c)
#add_executable(${PROJECT_NAME} animated.c)

target_link_libraries(${PROJECT_NAME} bmpc)
