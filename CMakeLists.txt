# Refreshing keyword: hud

cmake_minimum_required(VERSION 3.0)
project(Game)

set(MAIN_COMMON_HEADER_DIR "src/main_loops/incl")

set(GRAPHICS_HEADER_DIR "src/graphics")
set(UTILS_DIR "src/utils/logging")
set(SERVER_BASE "src/network/server")
set(SERVER_HEADER_DIR "${SERVER_BASE}/incl")

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(libs/glfw)

option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_BUILD_SAMPLES OFF)
option(ASSIMP_BUILD_TESTS OFF)
add_subdirectory(libs/assimp)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /std:c++17 /permissive- /experimental:external /external:anglebrackets /external:W0 /D NOMINMAX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++17 -O2")
    if(NOT WIN32)
        set(GLAD_LIBRARIES dl)
    endif()
endif()

include_directories(src/)
include_directories(libs/assimp/include/
                    libs/glad/include/
                    libs/glfw/include/
                    libs/glm/
                    libs/spdlog/include/)

file(GLOB VENDORS_SOURCES libs/glad/src/glad.c)
file(GLOB CLIENT_HEADERS ${GRAPHICS_HEADER_DIR}/incl/*.h
                         ${UTILS_DIR}/*.h)
file(GLOB CLIENT_SOURCES ${GRAPHICS_HEADER_DIR}/src/*.cpp
                         ${UTILS_DIR}/*.cpp)
file(GLOB SERVER_HEADERS ${SERVER_BASE}/incl/*.h)
file(GLOB SERVER_SOURCES ${SERVER_BASE}/src/*.cpp)

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



########################################
# Executables
########################################
add_executable(${PROJECT_NAME}-Client ${CLIENT_HEADERS}
                                      ${CLIENT_SOURCES}
                                      ${VENDORS_SOURCES} src/main_loops/src/client_loop.cpp)

add_executable(${PROJECT_NAME}-Server ${SERVER_SOURCES}
                                      src/main_loops/src/server_loop.cpp)

########################################
# Libraries
########################################
target_link_libraries(${PROJECT_NAME}-Client assimp glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES})

########################################
# Includes
# Note: both libs and includes must go
# AFTER executables section
########################################

########################################
# Client Includes
########################################

target_include_directories(${PROJECT_NAME}-Client PRIVATE ${GRAPHICS_HEADER_DIR})
target_include_directories(${PROJECT_NAME}-Client PRIVATE ${MAIN_COMMON_HEADER_DIR})
target_include_directories(${PROJECT_NAME}-Client PRIVATE ${UTILS_DIR})

########################################
# Server Includes
########################################

target_include_directories(${PROJECT_NAME}-Server PRIVATE ${SERVER_HEADER_DIR})
target_include_directories(${PROJECT_NAME}-Server PRIVATE ${MAIN_COMMON_HEADER_DIR})


########################################
# Target Output
########################################
set_target_properties(${PROJECT_NAME}-Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}-Server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})