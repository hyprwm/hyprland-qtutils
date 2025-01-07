cmake_minimum_required(VERSION 3.16)

project(hyprland-donate-screen VERSION ${VER} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Widgets Quick QuickControls2 WaylandClient)
find_package(PkgConfig REQUIRED)

pkg_check_modules(hyprutils REQUIRED IMPORTED_TARGET hyprutils)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(hyprland-donate-screen
    main.cpp
    DonateScreen.cpp
)

qt_add_qml_module(hyprland-donate-screen
    URI org.hyprland.donate-screen
    VERSION 1.0
    QML_FILES main.qml
)

target_link_libraries(hyprland-donate-screen PRIVATE
    Qt6::Widgets Qt6::QuickControls2 Qt6::WaylandClientPrivate PkgConfig::hyprutils
)


include(GNUInstallDirs)
install(TARGETS hyprland-donate-screen
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
