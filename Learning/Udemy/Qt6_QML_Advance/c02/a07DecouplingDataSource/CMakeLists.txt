cmake_minimum_required(VERSION 3.16)

project(a07DecouplingDataSource VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick QuickControls2)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appa07DecouplingDataSource
    main.cpp
)

qt_add_qml_module(appa07DecouplingDataSource
    URI a07DecouplingDataSource
    VERSION 1.0
    QML_FILES
        Main.qml
        SOURCES person.h person.cpp
        SOURCES personmodel.h personmodel.cpp
        QML_FILES InputDialog.qml
        SOURCES datasource.h datasource.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appa07DecouplingDataSource PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appa07DecouplingDataSource
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appa07DecouplingDataSource
    PRIVATE Qt6::Quick Qt6::QuickControls2
)

include(GNUInstallDirs)
install(TARGETS appa07DecouplingDataSource
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
