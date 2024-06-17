cmake_minimum_required(VERSION 3.16)

project(rect_cut_app VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick LinguistTools)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(rect_cut
    app/main.cpp
)

qt_add_qml_module(rect_cut
    URI rect_cut_app
    VERSION 1.0
    QML_FILES ui/Main.qml
)

qt_add_lupdate(rect_cut
    TS_FILES ts/rect_cut_ru_RU.ts
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(rect_cut PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appuntitled_test
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(rect_cut
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS rect_cut
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
