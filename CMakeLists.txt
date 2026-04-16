cmake_minimum_required(VERSION 4.1)

project("Physics 2D Platformer SDL -version3")

set(CMAKE_CXX_STANDARD 17)

include_directories(include C:/SDL3-w64/include)
link_directories(C:/SDL3-w64/lib)

add_executable(
	main WIN32
	src/main.cpp 
	src/clock.cpp
	src/entity.cpp
	src/game.cpp
)


target_link_libraries(main mingw32 SDL3 SDL3_image)

install(TARGETS main
    RUNTIME DESTINATION release
)

install(FILES
    C:/SDL3-w64/bin/SDL3.dll
    C:/SDL3-w64/bin/SDL3_image.dll
    C:/mingw64/bin/libatomic-1.dll
    C:/mingw64/bin/libgcc_s_seh-1.dll
    C:/mingw64/bin/libgomp-1.dll
    C:/mingw64/bin/libquadmath-0.dll
    C:/mingw64/bin/libssp-0.dll
    C:/mingw64/bin/libstdc++-6.dll
    C:/mingw64/bin/libwinpthread-1.dll
    DESTINATION release
)

install(DIRECTORY
	res
	DESTINATION release
)