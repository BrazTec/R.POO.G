cmake_minimum_required(VERSION 4.0)
project(jogoascii)

set(CMAKE_CXX_STANDARD 20)

add_executable(jogoascii src/main.cpp
        src/Character.cpp
        src/Character.h
        src/Player.cpp
        src/Player.h
        src/Enemy.cpp
        src/Enemy.h
        src/Game.cpp
        src/Game.h
)
