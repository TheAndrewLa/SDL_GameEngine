cmake_minimum_required(VERSION 3.22)
project(boong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(SDL_INCLUDE_PATH D:\\cpp_libs\\SDL2\\SDL2-2.24.0\\include)
set(SDL_LIB_PATH D:\\cpp_libs\\SDL2\\SDL2-2.24.0\\lib\\x64)

set(SDL_IMAGE_INCLUDE_PATH D:\\cpp_libs\\SDL2\\Image-2.6.2\\include)
set(SDL_IMAGE_LIB_PATH D:\\cpp_libs\\SDL2\\Image-2.6.2\\lib\\x64)

set(SDL_TTF_INCLUDE_PATH D:\\cpp_libs\\SDL2\\TTF-2.20.1\\include)
set(SDL_TTF_LIB_PATH D:\\cpp_libs\\SDL2\\TTF-2.20.1\\lib\\x64)

include_directories(${SDL_INCLUDE_PATH})
include_directories(${SDL_IMAGE_INCLUDE_PATH})
include_directories(${SDL_TTF_INCLUDE_PATH})

link_directories(${SDL_LIB_PATH})
link_directories(${SDL_IMAGE_LIB_PATH})
link_directories(${SDL_TTF_LIB_PATH})

add_executable(${PROJECT_NAME} Main.cpp)
target_link_libraries(${PROJECT_NAME} SDL2Main SDL2 SDL2_image SDL2_ttf)
