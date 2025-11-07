cmake_minimum_required(VERSION 3.16)

project(QDBusServer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS DBus)

qt_add_executable(appQDBusServer
    main.cpp
)

qt_add_qml_module(appQDBusServer
    URI QDBusServer
    VERSION 1.0
    QML_FILES main.qml
    SOURCES helloservice.h helloservice.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appQDBusServer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appQDBusServer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appQDBusServer
    PRIVATE Qt6::Quick)
target_link_libraries(appQDBusServer PRIVATE Qt6::Core)
target_link_libraries(appQDBusServer PRIVATE Qt6::DBus)

include(GNUInstallDirs)
install(TARGETS appQDBusServer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
