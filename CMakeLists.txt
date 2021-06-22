cmake_minimum_required(VERSION 3.13)
project(Brik)

## SOURCES ##

add_executable(Brik
    src/Ball.cpp
    src/Ball.h
    src/Breakable.cpp
    src/Breakable.h
    src/Brik.cpp
    src/EventManager.cpp
    src/EventManager.h
    src/Map.cpp
    src/Map.h
    src/Slider.cpp
    src/Slider.h
    src/Physics/Bounce.cpp
    src/Physics/Bounce.h
    src/Physics/Geometry.h
    src/Physics/Intersect.cpp
    src/Physics/Intersect.h
)

## COMPILE OPTIONS ##

target_compile_features(Brik PRIVATE cxx_std_17)

if(MSVC)
    target_compile_options(Brik PRIVATE /W4 /WX)
else()
    target_compile_options(Brik PRIVATE -Wall -Wextra -Werror -Wshadow)
endif()

## SFML ##

find_package(SFML COMPONENTS graphics window system)
target_link_libraries(Brik PRIVATE sfml-graphics sfml-window sfml-system)

if (WIN32)
    add_custom_command(TARGET Brik POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            "$<TARGET_FILE_DIR:Brik>/")
    add_custom_command(TARGET Brik POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-window>
            "$<TARGET_FILE_DIR:Brik>/")
    add_custom_command(TARGET Brik POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-system>
            "$<TARGET_FILE_DIR:Brik>/")
endif()
