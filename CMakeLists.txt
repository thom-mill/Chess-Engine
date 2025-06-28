cmake_minimum_required(VERSION 3.28)

project(Chess-Engine)

set(CMAKE_CXX_STANDARD 11)
add_executable(Chess-Engine main.cpp
        game_state.h
        game_state.cpp
        gui.cpp
)

set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(SFML_DIR /opt/homebrew/Cellar/sfml/2.6.1/ilb/cmake/SFML)

find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)

include_directories(/opt/homebrew/Cellar/sfml/2.6.1/lib/cmake/SFML)

target_link_libraries(Chess-Engine sfml-system sfml-window sfml-graphics sfml-audio)