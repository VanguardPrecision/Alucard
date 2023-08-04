cmake_minimum_required(VERSION 3.22)
project(Alucard VERSION 1.0)

message("Alucard Version: ${Alucard_VERSION}")

# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#For visual studio builders set the CMAKE_SUPPRESS_REGENERATION to OFF or leave it commented.
#set(CMAKE_SUPPRESS_REGENERATION OFF)

set(SOURCES
    Alucard.cpp
)

add_executable(Alucard ${SOURCES})

find_package(libzip REQUIRED HINTS "/home/diablo/Downloads/libzip-1.10.0/build")

if (NOT libzip_FOUND)
    message(FATAL_ERROR "libzip package not found")
endif()

target_include_directories(Alucard
    PRIVATE
    ${libzip_INCLUDE_DIRS}
)
message("LibZip VERSION: ${libzip_VERSION}")

# Link against the required libraries
target_link_libraries(Alucard 
    PRIVATE

    ${Libzip_LIBRARIES}
)
