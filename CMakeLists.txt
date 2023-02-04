cmake_minimum_required(VERSION 3.0)
project(Chip8Emulator)

set(SRCS
    main.cpp
    Memory/Memory.cpp
    Cartridge/Cartridge.cpp
    )
    
set(HEADERS
    Memory/Memory.h
    Cartridge/Cartridge.h
    )

add_executable(Chip8Emulator ${SRCS} ${HEADERS})
