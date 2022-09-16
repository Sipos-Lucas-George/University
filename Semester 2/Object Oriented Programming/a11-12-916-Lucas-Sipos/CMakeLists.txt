cmake_minimum_required(VERSION 3.21)
project(a11-12-916-Lucas-Sipos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(a11-12-916-Lucas-Sipos main.cpp
        main.cpp
        UI/UI.cpp
        UI/UI.h
        Domain/Movie.cpp
        Domain/Movie.h
        Repository/Repository.cpp
        Repository/Repository.h
        Service/Service.cpp
        Service/Service.h
        Repository/WatchList.cpp
        Repository/WatchList.h
        Tests/Tests.cpp
        Tests/Tests.h
        ExceptionsValidators/Exceptions.cpp
        ExceptionsValidators/Exceptions.h
        ExceptionsValidators/Validator.cpp
        ExceptionsValidators/Validator.h
        Repository/CSVWatchList.cpp
        Repository/CSVWatchList.h
        Repository/HTMLWatchList.cpp
        Repository/HTMLWatchList.h
        GUI/gui.cpp GUI/gui.h GUI/gui.ui GUI/startgui.cpp GUI/startgui.h GUI/startgui.ui)
target_link_libraries(a11-12-916-Lucas-Sipos
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if(WIN32)
    set(DEBUG_SUFFIX)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if(NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif()
    endif()
    if(EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif()
    foreach(QT_LIB Core Gui Widgets )
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach(QT_LIB)
endif()
