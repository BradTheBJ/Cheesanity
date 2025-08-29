cmake_minimum_required(VERSION 3.10)
project(MovingBlock)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set SFML directory (CMake config location)
set(SFML_DIR "D:/Dev/Libraries for cpp/SFML-2.6.2/lib/cmake/SFML")

# Find SFML 2.6
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

# Sources
set(SOURCES
        Scripts/main.cpp
        Scripts/board.cpp
        Scripts/Letters.cpp
        Scripts/pawn.cpp
        # add other cpp files here
)

add_executable(${PROJECT_NAME} ${SOURCES})

# Link SFML
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)

# Copy SFML DLLs to output folder
if(WIN32 AND SFML_FOUND)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            "D:/Dev/Libraries for cpp/SFML-2.6.2/bin"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()

# Copy Sprites folder to build directory so textures can be loaded with relative paths
file(COPY "${CMAKE_SOURCE_DIR}/Sprites"
        DESTINATION "${CMAKE_BINARY_DIR}")
