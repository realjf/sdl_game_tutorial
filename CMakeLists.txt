cmake_minimum_required(VERSION 3.12)

if(TEST_APP)
    set(PROJECT_NAME sdl_game_tutorial_test)
else()
    set(PROJECT_NAME sdl_game_tutorial)
endif()

set(SDLGAME_MAJOR_VERSION 0)
set(SDLGAME_MINOR_VERSION 0)
set(SDLGAME_MICRO_VERSION 1)
set(SDLGAME_VERSION "${SDLGAME_MAJOR_VERSION}.${SDLGAME_MINOR_VERSION}.${SDLGAME_MICRO_VERSION}")

project(${PROJECT_NAME} LANGUAGES C CXX VERSION ${SDLGAME_VERSION})

# if(CMAKE_VERSION VERSION_GREATER 3.12)
# set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
# endif()
if(POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

# set executable output path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# set library output path
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(CMAKE_VERBOSE_MAKEFILE ON)

include(cmake/common.cmake)
include(cmake/comm_macros.cmake)

include_directories(.)
include_directories(src)
include_directories(deps/SDL2/include)
include_directories(deps/SDLIMG)
include_directories(deps/SDLTTF)
include_directories(deps/SDLMIXER/include)
include_directories(deps/SDLNET)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-volatile -g -O2")

if(TEST_APP)
    SETUP_TEST(${PROJECT_NAME} ${SDLGAME_VERSION})
else()
    SETUP_APP(${PROJECT_NAME} ${SDLGAME_VERSION})
endif()

target_link_directories(${PROJECT_NAME} PUBLIC ${LIBRARY_OUTPUT_PATH})
target_link_libraries(${PROJECT_NAME} SDL2 SDL2_image-2.0 SDL2_ttf-2.0 SDL2_mixer-2.0)
