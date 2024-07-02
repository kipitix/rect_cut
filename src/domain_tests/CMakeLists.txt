cmake_minimum_required(VERSION 3.5)

project(domain_tests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Core Gui)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(domain_tests tst_domain.cpp)
add_test(NAME domain_tests COMMAND Domain)

target_include_directories(domain_tests
    PRIVATE ../domain
)

target_link_libraries(domain_tests
    PRIVATE Qt${QT_VERSION_MAJOR}::Test Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui
    domain
)

