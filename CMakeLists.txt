cmake_minimum_required(VERSION 3.21)
project(SpaceInvaders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SpaceInvaders src/main.cpp
        src/MainApp.cpp
        src/MainApp.h
        src/MainFrame.cpp
        src/MainFrame.h)

if (MSVC)
    find_package(wxWidgets CONFIG REQUIRED)
    target_link_libraries(SpaceInvaders PRIVATE wx::core wx::base)
elseif (MINGW)
    find_package(wxWidgets REQUIRED COMPONENTS core base)
    include(${wxWidgets_USE_FILE})
    target_link_libraries(SpaceInvaders PRIVATE ${wxWidgets_LIBRARIES})
else()
    find_package(wxWidgets REQUIRED COMPONENTS core base)
    target_link_libraries(SpaceInvaders PRIVATE wxWidgets::wxWidgets)
endif()

if (WIN32)
    set_target_properties(SpaceInvaders PROPERTIES WIN32_EXECUTABLE ON)
endif()
