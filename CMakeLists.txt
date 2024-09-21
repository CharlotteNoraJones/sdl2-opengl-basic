cmake_minimum_required(VERSION 3.15.0)

project(HelloSDl2 LANGUAGES C CXX)

include(FetchContent)

#SDL2
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    sdl2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL 
    GIT_TAG release-2.30.7
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(sdl2)

#GLAD
add_subdirectory(external/glad/)

add_executable(HelloSDl2 src/main.cpp)

if (MSVC)
    target_compile_options(HelloSDl2 PRIVATE /W4)
else()
    target_compile_options(HelloSDl2 PRIVATE -Wall -Wextra -pedantic)
endif()

set_target_properties(HelloSDl2 PROPERTIES 
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS OFF)

target_link_libraries(HelloSDl2 PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(HelloSDl2 PRIVATE glad)