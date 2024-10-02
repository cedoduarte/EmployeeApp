cmake_minimum_required(VERSION 3.16)

project(EmployeeApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Sql)

set(PROJECT_SOURCES
        main.cpp
        views/mainwindow.cpp
        views/mainwindow.h
        views/mainwindow.ui
        views/managerselectordialog.h views/managerselectordialog.cpp views/managerselectordialog.ui
        sql/employeeinserter.h sql/employeeinserter.cpp
        sql/sqlserver.h
        populators/icombopopulator.h
        populators/jobtitlecombopopulator.h populators/jobtitlecombopopulator.cpp
        populators/departmentcombopopulator.h populators/departmentcombopopulator.cpp
        preparators/ilineeditpreparator.h
        preparators/emaillineeditpreparator.h preparators/emaillineeditpreparator.cpp
        preparators/salarylineeditpreparator.h preparators/salarylineeditpreparator.cpp        
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(EmployeeApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET EmployeeApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(EmployeeApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(EmployeeApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(EmployeeApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(EmployeeApp PRIVATE Qt${QT_VERSION_MAJOR}::Sql)
target_link_directories(EmployeeApp PRIVATE .)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.EmployeeApp)
endif()
set_target_properties(EmployeeApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS EmployeeApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(EmployeeApp)
endif()
