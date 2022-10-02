cmake_minimum_required(VERSION 3.22)
project(boong)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")

set(SDL_INCLUDE_PATH D:\\cpp_libs\\SDL2\\SDL2-2.24.0\\include)
set(SDL_LIB_PATH D:\\cpp_libs\\SDL2\\SDL2-2.24.0\\lib\\x64)

set(SDL_IMAGE_INCLUDE_PATH D:\\cpp_libs\\SDL2\\Image-2.6.2\\include)
set(SDL_IMAGE_LIB_PATH D:\\cpp_libs\\SDL2\\Image-2.6.2\\lib\\x64)

set(SDL_TTF_INCLUDE_PATH D:\\cpp_libs\\SDL2\\TTF-2.20.1\\include)
set(SDL_TTF_LIB_PATH D:\\cpp_libs\\SDL2\\TTF-2.20.1\\lib\\x64)

set(SDL_MIXER_INCLUDE_PATH D:\\cpp_libs\\SDL2\\Mixer-2.6.2\\include)
set(SDL_MIXER_LIB_PATH D:\\cpp_libs\\SDL2\\Mixer-2.6.2\\lib\\x64)

include_directories(${SDL_INCLUDE_PATH})
include_directories(${SDL_IMAGE_INCLUDE_PATH})
include_directories(${SDL_TTF_INCLUDE_PATH})
include_directories(${SDL_MIXER_INCLUDE_PATH})

link_directories(${SDL_LIB_PATH})
link_directories(${SDL_IMAGE_LIB_PATH})
link_directories(${SDL_TTF_LIB_PATH})
link_directories(${SDL_MIXER_LIB_PATH})

set(ENGINE_FILES
        Engine/_Definitions.h
        Engine/Window.cpp Engine/Window.h
        Engine/Sprite.cpp Engine/Sprite.h
        Engine/Timer.cpp Engine/Timer.h
        Engine/Sounds.cpp Engine/Sounds.h)

add_executable(${PROJECT_NAME} Main.cpp ${ENGINE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2Main SDL2 SDL2_image SDL2_ttf SDL2_mixer)
