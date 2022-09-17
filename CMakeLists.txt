cmake_minimum_required(VERSION 3.21)

# Project name
set(EXECUTABLE_NAME MyGame)
project(${EXECUTABLE_NAME} LANGUAGES CXX)

# Include SFML
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

# Adding code and linking lbiraries
add_executable(${EXECUTABLE_NAME} src/main.cpp src/Game.cpp)
include_directories(include)
target_link_libraries(${EXECUTABLE_NAME} PRIVATE sfml-graphics)
target_compile_features(${EXECUTABLE_NAME} PRIVATE cxx_std_17)

# Windows shizzle
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${EXECUTABLE_NAME}> $<TARGET_FILE_DIR:${EXECUTABLE_NAME}> COMMAND_EXPAND_LISTS)
endif()

# Not sure what this does
install(TARGETS ${EXECUTABLE_NAME})
