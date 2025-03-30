cmake_minimum_required(VERSION 3.14)

# Source files for LRL_Tools - you may need to add all your source files
file(GLOB LRL_TOOLS_SOURCES "*.cpp" "*.c")
file(GLOB LRL_TOOLS_HEADERS "*.h" "*.hpp")

add_library(LRL_Tools ${LRL_TOOLS_SOURCES} ${LRL_TOOLS_HEADERS})

target_include_directories(LRL_Tools 
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(LRL_Tools PUBLIC cxx_std_20)

# Add debug/release specific build flags
target_compile_options(LRL_Tools PRIVATE
    $<$<CONFIG:Debug>:/W3 /sdl>
    $<$<CONFIG:Release>:/W3 /sdl /O2 /Oi /GL>
)

target_compile_definitions(LRL_Tools PRIVATE
    $<$<CONFIG:Debug>:_DEBUG>
    $<$<CONFIG:Release>:NDEBUG>
)
