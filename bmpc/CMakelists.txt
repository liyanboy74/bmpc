cmake_minimum_required(VERSION 3.6)

project(bmpc)

add_library(${PROJECT_NAME} bmpc.c)

target_link_libraries(${PROJECT_NAME} bmp color)
include_directories(../bmp ../color .)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES bmpc.h DESTINATION include)
