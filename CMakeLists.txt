cmake_minimum_required(VERSION 3.0)
project(Chip8Emulator)

set(SRCS
    main.cpp
    Memory/Memory.cpp
    Cartridge/Cartridge.cpp
    CPU/CPU.cpp
    Registry/Registry.cpp
    OpCodeTable/OpCodeTable.cpp
    InstructionProcessor/InstructionProcessor.cpp
    Clock/Clock.cpp
    )
    
set(HEADERS
    Memory/Memory.h
    Cartridge/Cartridge.h
    CPU/CPU.h
    Registry/Registry.h
    OpCodeTable/OpCodeTable.h
    InstructionProcessor/InstructionProcessor.h
    Clock/Clock.h
    )

#set(CMAKE_BUILD_TYPE Debug)

# Specifiez le chemin vers le dossier SDL que vous avez extrait
set(SDL2_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL2")

find_package(SDL2 REQUIRED)

# Incluez les en-tetes SDL2
include_directories(${SDL2_INCLUDE_DIRS})

# Ajoutez une source à l'executable de ce projet.
add_executable(Chip8Emulator ${SRCS} ${HEADERS})



# Liez la bibliothèque SDL2 à votre executable
#Version compilateur Mingw32
target_link_libraries(Chip8Emulator ${SDL2_LIBRARIES})
#Version compilateur MSVC 64
#target_link_libraries(Chip8Emulator SDL2::SDL2 SDL2::SDL2main)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Chip8Emulator PROPERTY CXX_STANDARD 20)
endif()