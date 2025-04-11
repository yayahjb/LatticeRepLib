cmake_minimum_required(VERSION 3.14)

# Source files for LatticeRepresentationLib - you may need to add all your source files
file(GLOB LATTICE_REP_SOURCES "*.cpp" "*.c")
file(GLOB LATTICE_REP_HEADERS "*.h" "*.hpp")

add_library(LatticeRepresentationLib ${LATTICE_REP_SOURCES} ${LATTICE_REP_HEADERS})

target_include_directories(LatticeRepresentationLib 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(LatticeRepresentationLib 
    PUBLIC 
        LRL_Tools
)

target_compile_features(LatticeRepresentationLib PUBLIC cxx_std_20)

# Add debug/release specific build flags
target_compile_options(LatticeRepresentationLib PRIVATE
    $<$<CONFIG:Debug>:/W3 /sdl>
    $<$<CONFIG:Release>:/W3 /sdl /O2 /Oi /GL>
)

target_compile_definitions(LatticeRepresentationLib PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)

