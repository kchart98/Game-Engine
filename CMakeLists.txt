cmake_minimum_required(VERSION 2.6)
project(GAMEENGINE)

include_directories(
	src
	contrib
)

if(MSVC)
  include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
  )

  link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
  )
else()
  include_directories(
    /usr/X11R6/include
    /usr/local/include
  )

  link_directories(
    /usr/X11R6/lib
    /usr/local/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_library(HoneyComb
  src/HoneyComb/Core.cpp
  src/HoneyComb/Entity.cpp
  src/HoneyComb/Component.cpp
  src/HoneyComb/MeshRender.cpp
  src/HoneyComb/TextureResource.cpp
  src/HoneyComb/Shaders.cpp
  src/HoneyComb/VertexBuffer.cpp
  src/HoneyComb/VertexArray.cpp
  src/HoneyComb/Resources.cpp
  src/HoneyComb/Resource.cpp
)

if(MSVC)
  target_link_libraries(HoneyComb
    SDL2 glew32 opengl32
  )
else()
  target_link_libraries(HoneyComb
    SDL2 GLU GLEW GL
  )
endif()

add_executable(Game
  src/Game/main.cpp
)

target_link_libraries (Game HoneyComb)

if(MSVC)
  add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:Game>"
  )

  add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:Game>"
  )
endif()
