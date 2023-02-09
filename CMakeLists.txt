cmake_minimum_required(VERSION 3.16.3)
project(NeNotion)

set(CMAKE_CXX_STANDARD 14)

add_executable(NeNotion main.cpp
        Windows/Windows.cpp
        interfaceSFML/interfaceSFML.cpp
        Boards/Board.cpp)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/" ${CMAKE_MODULE_PATH})
#set(SFML_STATIC_LIBRARIES TRUE)
#set(SFML_DIR SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)


include_directories(SFML/include)
target_link_libraries(NeNotion sfml-system sfml-window sfml-graphics sfml-audio sfml-network)