cmake_minimum_required(VERSION 3.5)

project(Domain LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Domain tst_domain.cpp)
add_test(NAME Domain COMMAND Domain)

target_link_libraries(Domain PRIVATE Qt${QT_VERSION_MAJOR}::Test)

