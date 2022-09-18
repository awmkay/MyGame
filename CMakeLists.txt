cmake_minimum_required(VERSION 3.21)

# Project name
set(EXECUTABLE_NAME MyGame)
project(${EXECUTABLE_NAME} LANGUAGES CXX)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Adding code and linking lbiraries
set(TARGET_SRC
	src/Aircraft.cpp
	src/Entity.cpp
	src/Game.cpp
	src/ResourceHolder.cpp
	src/SceneNode.cpp
	src/SpriteNode.cpp
	src/World.cpp
	src/main.cpp)
include_directories(include)
add_executable(${EXECUTABLE_NAME} ${TARGET_SRC})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE sfml-graphics)
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)

# Not sure what this does
install(TARGETS ${EXECUTABLE_NAME})
