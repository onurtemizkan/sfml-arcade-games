cmake_minimum_required(VERSION 3.2)
project(SFML_Games)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp src/game/snake/snake.cpp src/game/snake/Snake.cpp src/game/snake/Snake.h src/game/pong/Pong.cpp src/game/arkanoid/Arkanoid.cpp)
add_executable(SFML_Games ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_Games ${SFML_LIBRARIES})
endif()