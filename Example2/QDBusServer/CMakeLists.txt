cmake_minimum_required(VERSION 3.16)
project(QDBusServer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ Only Core + DBus
find_package(Qt6 REQUIRED COMPONENTS Core DBus)

# ✅ No Quick / No GUI / No QML
qt_add_executable(appQDBusServer
    main.cpp
    helloservice.cpp
    helloservice.h
)

# ✅ Purely console executable
set_target_properties(appQDBusServer PROPERTIES
    MACOSX_BUNDLE FALSE
    WIN32_EXECUTABLE FALSE
)

target_link_libraries(appQDBusServer
    PRIVATE Qt6::Core
    PRIVATE Qt6::DBus
)

install(TARGETS appQDBusServer)
