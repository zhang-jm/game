# Refreshing keyword: hud

cmake_minimum_required(VERSION 3.0)
project(Game)

set(GLFW_BUILD_DOCS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
add_subdirectory(libs/glfw)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /std:c++17 /permissive- /experimental:external /external:anglebrackets /external:W0 /D NOMINMAX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17 -O2")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(src/)
include_directories(SYSTEM
                    libs/glad/include/
                    libs/glfw/include/
                    libs/glm/)

file(GLOB VENDORS_SOURCES libs/glad/src/glad.c)
file(GLOB_RECURSE GAME_HEADERS src/*.h)
file(GLOB_RECURSE GAME_SOURCES src/*.cpp)
#file(GLOB PROJECT_SHADERS src/graphics/*.comp
#                          src/graphics/*.frag
#                          src/graphics/*.geom
#                          src/graphics/*.vert)
file(GLOB PROJECT_CONFIGS CMakeLists.txt
                          Readme.md
                         .gitattributes
                         .gitignore
                         .gitmodules)

source_group("Headers" FILES ${PROJECT_HEADERS})
#source_group("Shaders" FILES ${PROJECT_SHADERS})
source_group("Sources" FILES ${PROJECT_SOURCES})
source_group("Vendors" FILES ${VENDORS_SOURCES})

add_definitions(-DGLFW_INCLUDE_NONE
                -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\")

add_executable(${PROJECT_NAME}-Client ${PROJECT_SOURCES} ${PROJECT_HEADERS}
                                      ${PROJECT_CONFIGS}
                                      ${VENDORS_SOURCES} src/main.cpp)

target_link_libraries(${PROJECT_NAME}-Client glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

set_target_properties(${PROJECT_NAME}-Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_NAME})