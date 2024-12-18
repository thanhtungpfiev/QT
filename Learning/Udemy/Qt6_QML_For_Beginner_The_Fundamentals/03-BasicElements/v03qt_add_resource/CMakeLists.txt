cmake_minimum_required(VERSION 3.16)

project(v03qt_add_resource VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appv03qt_add_resource
    main.cpp
)

#Method 1.
# qt_add_resources(appv03qt_add_resource "qml"
#         PREFIX /
#         FILES
#                 images/LearnQt.png
# )

# qt_add_qml_module(appv03qt_add_resource
#     URI v03qt_add_resource
#     VERSION 1.0
#     QML_FILES Main.qml
# )

# Method 2.
qt_add_qml_module(appv03qt_add_resource
    URI v03qt_add_resource
    VERSION 1.0
    QML_FILES
        Main.qml
    #You can also do this instead of qt_add_resources
    RESOURCES
        images/LearnQt.png
    RESOURCE_PREFIX /
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appv03qt_add_resource PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appv03qt_add_resource
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appv03qt_add_resource
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appv03qt_add_resource
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
