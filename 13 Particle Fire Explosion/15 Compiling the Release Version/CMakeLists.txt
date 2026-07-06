cmake_minimum_required(VERSION 3.20)
project(pixelfire C)

include(FetchContent)

FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.0
)

FetchContent_MakeAvailable(SDL3)

add_executable(pixelfire
    main.c
    graphics.c
    hslrgb.c
    particle.c
    swarm.c
)

# Default to Release mode unless user specifies otherwise
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
endif()

# Universal optimisation flags (safe on all platforms)
target_compile_options(pixelfire PRIVATE
    -O3                # highest optimisation
    -ffast-math        # aggressive FP optimisations
    -funroll-loops     # loop unrolling
    -fstrict-aliasing  # assume strict aliasing rules
)

# Link-time optimisation (portable)
target_link_options(pixelfire PRIVATE
    -flto
)

target_link_libraries(pixelfire PRIVATE SDL3::SDL3)

