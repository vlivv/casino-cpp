cmake_minimum_required(VERSION 3.30)
project(kasynoProjekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(kasynoProjekt/projekt)

add_executable(kasynoProjekt
        kasynoProjekt/projekt/Bandyta.cpp
        kasynoProjekt/projekt/Bandyta.h
        kasynoProjekt/projekt/Blackjack.cpp
        kasynoProjekt/projekt/Blackjack.h
        kasynoProjekt/projekt/Gra.cpp
        kasynoProjekt/projekt/Gra.h
        kasynoProjekt/projekt/main.cpp
        kasynoProjekt/projekt/Menu.cpp
        kasynoProjekt/projekt/Menu.h
        kasynoProjekt/projekt/Ruletka.cpp
        kasynoProjekt/projekt/Ruletka.h)
