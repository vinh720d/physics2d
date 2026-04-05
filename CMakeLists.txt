cmake_minimum_required(VERSION 4.1)

project("Physics 2D Platformer SDL -version3")

set(CMAKE_CXX_STANDARD 17)

include_directories(include C:/SDL3-w64/include)
link_directories(C:/SDL3-w64/lib)

add_executable(main src/main.cpp)

target_link_libraries(main mingw32 SDL3 SDL3_image)