cmake_minimum_required(VERSION 3.14)

# Project name
project(Duck10 VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Options
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Add subdirectories for libraries
add_subdirectory(LRL_Tools)
add_subdirectory(LatticeRepresentationLib)
add_subdirectory(InputHandler)

# Common compile definitions based on configuration
set(COMMON_DEBUG_DEFS _DEBUG _CONSOLE)
set(COMMON_RELEASE_DEFS NDEBUG _CONSOLE)

# Command-line executables

# CmdCmplx
add_executable(CmdCmplx CmdCmplx.cpp)
target_link_libraries(CmdCmplx PRIVATE LatticeRepresentationLib LRL_Tools)

# CmdDelone
add_executable(CmdDelone CmdDelone.cpp CmdDeloneControls.h)
target_link_libraries(CmdDelone PRIVATE InputHandler LatticeRepresentationLib LRL_Tools)
target_include_directories(CmdDelone PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# CmdDists
add_executable(CmdDists CmdDists.cpp CmdDistsControls.h LatticeRepresentationLib/CS6Dist.c LatticeRepresentationLib/CS6Dist.h)
target_link_libraries(CmdDists PRIVATE InputHandler LatticeRepresentationLib LRL_Tools)

# B4_rotations
add_executable(B4_rotations B4_rotations.cpp)
target_link_libraries(B4_rotations PRIVATE LatticeRepresentationLib LRL_Tools)

# BUnique
add_executable(BUnique BUnique.cpp)
target_link_libraries(BUnique PRIVATE LatticeRepresentationLib LRL_Tools)

# C3Plot
add_executable(C3Plot C3Plot.cpp C3Plot.h)
target_link_libraries(C3Plot PRIVATE LatticeRepresentationLib LRL_Tools)

# CheckInput
add_executable(CheckInput CheckInput.cpp CheckInputControls.h)
target_link_libraries(CheckInput PRIVATE InputHandler LatticeRepresentationLib LRL_Tools)

# Claude2
add_executable(Claude2 Claude2.cpp)
target_link_libraries(Claude2 PRIVATE LatticeRepresentationLib LRL_Tools)

# Claude3
add_executable(Claude3 Claude3.cpp)
target_link_libraries(Claude3 PRIVATE LatticeRepresentationLib LRL_Tools)

# CmdBounds
add_executable(CmdBounds CmdBounds.cpp)
target_link_libraries(CmdBounds PRIVATE LatticeRepresentationLib LRL_Tools)

# Set compiler-specific options based on configuration
foreach(target 
        CmdCmplx CmdDelone CmdDists B4_rotations BUnique C3Plot 
        CheckInput Claude2 Claude3 CmdBounds)
    target_compile_options(${target} PRIVATE
        $<$<CONFIG:Debug>:/W3 /sdl>
        $<$<CONFIG:Release>:/W3 /sdl /O2 /Oi /GL>
    )
    
    target_compile_definitions(${target} PRIVATE
        $<$<CONFIG:Debug>:${COMMON_DEBUG_DEFS}>
        $<$<CONFIG:Release>:${COMMON_RELEASE_DEFS}>
    )
    
    # Link options for Release builds (optimization)
    target_link_options(${target} PRIVATE
        $<$<CONFIG:Release>:/LTCG /OPT:REF /OPT:ICF>
    )
endforeach()

