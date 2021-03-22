cmake_minimum_required(VERSION 3.17)
project(PingPong)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} main.cpp Config.cpp Player.cpp)

include_directories(headers)
set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

if(SFML_FOUND)
    set(SFML_LIBS sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})
endif()
