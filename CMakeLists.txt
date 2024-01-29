cmake_minimum_required(VERSION 3.24)
project(Snake_Game)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(Snake_Game
        Logic.cpp
        Logic.h
        main.cpp
        Board.cpp
        Board.h)

# Link against ncurses library
target_link_libraries(Snake_Game ncurses tinfo)
