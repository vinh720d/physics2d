cmake_minimum_required(VERSION 4.1)

project("Physics 2D Platformer SDL -version3")

set(CMAKE_CXX_STANDARD 17)

include_directories(include C:/SDL3-w64/include)
link_directories(C:/SDL3-w64/lib)

file(GLOB_RECURSE EXE_FILES "src/*.cpp")
add_executable(main WIN32 ${EXE_FILES})

target_link_libraries(main mingw32 SDL3 SDL3_image)

install(TARGETS main
    RUNTIME DESTINATION release
)

file(GLOB_RECURSE SDL_DLLS "C:/SDL3-w64/bin/*.dll")
file(GLOB_RECURSE MINGW_DLLS "C:/mingw64/bin/*.dll")

add_custom_command(
    TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            C:/SDL3-w64/bin/
            $<TARGET_FILE_DIR:main>
)

install(FILES
    ${SDL_DLLS}
    ${MINGW_DLLS}
    DESTINATION release
)

install(DIRECTORY
	res
	DESTINATION release
)