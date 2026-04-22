mingw64 link:
https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-win32/seh/x86_64-8.1.0-release-win32-seh-rt_v6-rev0.7z/download

make sure the path: C:/mingw64 exists


cmake version at least 4.1.0

cmake link:
https://github.com/Kitware/CMake/releases/download/v4.3.1/cmake-4.3.1-windows-x86_64.msi


SDL: SDL3

SDL3 link:
https://github.com/libsdl-org/SDL/releases/download/release-3.4.4/SDL3-devel-3.4.4-mingw.tar.gz

make sure the path: C:/SDL3-w64 exists



bash:
cmake -B build -DCMAKE_INSTALL_PREFIX=. -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -G "MinGW Makefiles"
cmake --build build
cmake --install build

