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

# Link against the required libraries
target_link_libraries(Alucard ${Boost_LIBRARIES})