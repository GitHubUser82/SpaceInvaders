cmake_minimum_required(VERSION 3.21)
project(SpaceInvaders LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SpaceInvaders
        src/main.cpp
        src/MainApp.cpp
        src/MainFrame.cpp
        src/OpenGLFrame.cpp
)

# wxWidgets (vcpkg / CONFIG mode)
find_package(wxWidgets CONFIG REQUIRED COMPONENTS core base gl)

target_link_libraries(SpaceInvaders PRIVATE
        wx::core
        wx::base
        wx::gl
        opengl32
)

if (WIN32)
    set_target_properties(SpaceInvaders PROPERTIES
            WIN32_EXECUTABLE ON
    )
endif()
