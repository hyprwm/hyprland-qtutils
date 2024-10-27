cmake_minimum_required(VERSION 3.16)

# Get version
file(READ "${CMAKE_SOURCE_DIR}/VERSION" VER_RAW)
string(STRIP ${VER_RAW} VER)

project(hyprland-qtutils VERSION ${VER} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets Quick QuickControls2 WaylandClient)
find_package(PkgConfig REQUIRED)

pkg_check_modules(hyprutils REQUIRED IMPORTED_TARGET hyprutils)

qt_standard_project_setup(REQUIRES 6.5)

add_subdirectory(utils/dialog)

