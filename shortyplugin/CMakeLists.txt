cmake_minimum_required(VERSION 3.16.0)

project(shortyplugin VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Qml REQUIRED)
find_package(Qt6 COMPONENTS Quick REQUIRED)

add_library(shortyplugin SHARED
    shorty_plugin.cpp
    shorty.cpp
    shorty_plugin.h
    shorty.h
)

target_link_libraries(shortyplugin PRIVATE Qt6::Core Qt6::Qml Qt6::Quick)

# THIS IS WORK IN PROGRESS - FOR NOW, IT BUILDS, BUT THE INSTALLATION IS MISSING

#set_target_properties(targetProject PROPERTIES
#   RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/plugins/${QmlPluginName}/)

#add_custom_command(TARGET ${targetProject} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy
#    ${QML_DIR_FILE}
#    ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/plugins/${QmlPluginName}/qmldir)

#TARGET = $$qtLibraryTarget($$TARGET)
#uri = org.qmlbook.utils

## Input
#SOURCES += \
    #shorty_plugin.cpp \
    #shorty.cpp

#HEADERS += \
    #shorty_plugin.h \
    #shorty.h

#OTHER_FILES = qmldir

#!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    #copy_qmldir.target = $$OUT_PWD/qmldir
    #copy_qmldir.depends = $$_PRO_FILE_PWD_/qmldir
    #copy_qmldir.commands = $(COPY_FILE) \"$$replace(copy_qmldir.depends, /, $$QMAKE_DIR_SEP)\" \"$$replace(copy_qmldir.target, /, $$QMAKE_DIR_SEP)\"
    #QMAKE_EXTRA_TARGETS += copy_qmldir
    #PRE_TARGETDEPS += $$copy_qmldir.target
#}

#qmldir.files = qmldir
#unix {
    #installPath = $$[QT_INSTALL_QML]/$$replace(uri, \\., /)
    #qmldir.path = $$installPath
    #target.path = $$installPath
    #INSTALLS += target qmldir
#}
