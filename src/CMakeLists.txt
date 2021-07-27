cmake_minimum_required(VERSION 3.16.0)

project(shorty VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Qml REQUIRED)
find_package(Qt6 COMPONENTS Quick REQUIRED)

add_executable(shorty
    shorty.cpp
    main.cpp
)

target_link_libraries(shorty PRIVATE Qt6::Core Qt6::Qml Qt6::Quick)
