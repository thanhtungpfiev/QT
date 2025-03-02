cmake_minimum_required(VERSION 3.16)

project(v13StatesTransitions VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appv13StatesTransitions
    main.cpp
)

qt_add_resources(appv13StatesTransitions "images"
        PREFIX /
        FILES
                images/treespringsmall.png
                images/treesummersmall.png
)

qt_add_qml_module(appv13StatesTransitions
    URI v13StatesTransitions
    VERSION 1.0
    QML_FILES
        Main.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appv13StatesTransitions PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appv13StatesTransitions
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appv13StatesTransitions
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appv13StatesTransitions
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
