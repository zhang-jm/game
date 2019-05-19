# Refreshing keyword: hud

cmake_minimum_required(VERSION 3.0)
project(Game)

set(MAIN_COMMON_HEADER_DIR "src/main_loops/incl")

set(GRAPHICS_HEADER_DIR "src/graphics")
set(UTILS_DIR "src/utils/*")
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
file(GLOB SERVER_HEADERS ${SERVER_BASE}/incl/*.h
                         ${UTILS_DIR}/*.h)
file(GLOB SERVER_SOURCES ${SERVER_BASE}/src/*.cpp
                         ${UTILS_DIR}/*.cpp)

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


add_subdirectory(./libs/grpc EXCLUDE_FROM_ALL)
message(STATUS "Using gRPC via add_subdirectory.")
                
# After using add_subdirectory, we can now use the grpc targets directly from
# this build.
set(_PROTOBUF_LIBPROTOBUF libprotobuf)
set(_PROTOBUF_PROTOC $<TARGET_FILE:protoc>)
set(_GRPC_GRPCPP_UNSECURE grpc++_unsecure)
set(_GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:grpc_cpp_plugin>)

# Proto file
#get_filename_component(actionHandler_proto "../../protos/helloworld.proto" ABSOLUTE)
#get_filename_component(actionHandler_proto_path "${hw_proto}" PATH)

# Generated sources
set(PROTOS_DIR "src/protos")
file(GLOB PROTO_SRCS ${PROTOS_DIR}/*.pb.cc)
file(GLOB PROTO_HDRS ${PROTOS_DIR}/src/*.pb.h)
file(GLOB GRPC_SRCS ${PROTOS_DIR}/*.grpc.pb.cc)
file(GLOB GRPC_HDRS ${PROTOS_DIR}/*.grpc.pb.h)
#set(ah_proto_srcs "./src/protos/input_handler.pb.cc")
#set(ah_proto_hdrs "./src/protos/input_handler.pb.h")
#set(ah_grpc_srcs "./src/protos/input_handler.grpc.pb.cc")
#set(ah_grpc_hdrs "./src/protos/input_handler.grpc.pb.h")

include_directories("./src/protos/")
########################################
# Executables
########################################
add_executable(${PROJECT_NAME}-Client ${CLIENT_HEADERS}
                                      ${CLIENT_SOURCES}
                                      ${VENDORS_SOURCES}
                                      ${GRPC_SRCS} ${PROTO_SRCS} src/main_loops/src/client_loop.cpp)

add_executable(${PROJECT_NAME}-Server ${SERVER_SOURCES} ${GRPC_SRCS} ${PROTO_SRCS}
                                      src/main_loops/src/server_loop.cpp)

########################################
# Libraries
########################################
target_link_libraries(${PROJECT_NAME}-Client assimp glfw
                      ${GLFW_LIBRARIES} ${GLAD_LIBRARIES}
                      ${_GRPC_GRPCPP_UNSECURE}
                      ${_PROTOBUF_LIBPROTOBUF})

target_link_libraries(${PROJECT_NAME}-Server
                      ${_GRPC_GRPCPP_UNSECURE}
                      ${_PROTOBUF_LIBPROTOBUF})
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
target_include_directories(${PROJECT_NAME}-Server PRIVATE "./src/protos/")

########################################
# Server Includes
########################################

target_include_directories(${PROJECT_NAME}-Server PRIVATE ${SERVER_HEADER_DIR})
target_include_directories(${PROJECT_NAME}-Server PRIVATE ${MAIN_COMMON_HEADER_DIR})
target_include_directories(${PROJECT_NAME}-Server PRIVATE "./src/protos/")



#protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=../../libs/grpc/bins/opt/grpc_cpp_plugin actionHandler.proto
#protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=../../libs/grpc/.build/Release/grpc_cpp_plugin.exe actionHandler.proto <- windows
#protoc -I . --cpp_out=. actionHandler.proto
# above  ran in proto folder to make code
########################################
# Target Output
########################################
set_target_properties(${PROJECT_NAME}-Client PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}-Server PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/${PROJECT_NAME})