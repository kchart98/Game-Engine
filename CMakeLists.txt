cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

add_executable(jumper
  src/jumper/main.cpp
  src/jumper/enitity.cpp
)

add_library(gameengine
  src/gameengine/entity.cpp
)

target_link_libraries (jumper.test.lib)