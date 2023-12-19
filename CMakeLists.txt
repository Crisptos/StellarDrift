cmake_minimum_required(VERSION 3.21)

# Config
project(StellarDrift VERSION 1.0.0 LANGUAGES C CXX ASM)

# Source
set(SOURCES
src/gameplay/tile.cpp
src/gameplay/world_gen.cpp
src/gameplay/gameplay_scene.cpp
src/gameplay/player.cpp
src/option_scene.cpp
src/character_scene.cpp
src/menu_scene.cpp
src/timer.cpp 
src/main.cpp
)
set(HEADERS
inc/gameplay/tile.h
inc/gameplay/entity.h
inc/gameplay/world_gen.h
inc/gameplay/gameplay_scene.h
inc/gameplay/player.h
inc/option_scene.h
inc/character_scene.h
inc/menu_scene.h
inc/scene.h
inc/util.h
vendor/raylib.h
)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)

# Libraries
include(FetchContent)
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG master)
FetchContent_MakeAvailable(raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raylib_SOURCE_DIR}/src/extras)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Options
target_compile_options(${PROJECT_NAME} PRIVATE $<$<CONFIG:DEBUG>:-DDEBUG>)