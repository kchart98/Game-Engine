cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	src
)

add_library(HoneyComb
  src/HoneyComb/Core.cpp
  src/HoneyComb/Entity.cpp
  src/HoneyComb/Component.cpp
)

add_executable(Game
  src/Game/main.cpp
)

target_link_libraries (Game HoneyComb)