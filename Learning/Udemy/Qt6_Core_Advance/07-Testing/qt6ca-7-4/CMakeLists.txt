cmake_minimum_required(VERSION 3.16)

project(qt6ca-7-4 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test)

add_executable(qt6ca-7-4
  main.cpp
  dog.h dog.cpp
)
target_link_libraries(qt6ca-7-4 Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Test)

include(GNUInstallDirs)
install(TARGETS qt6ca-7-4
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
