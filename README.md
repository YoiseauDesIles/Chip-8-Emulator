# emulateur Chip 8

Ce projet est une entrée en matière dans le developpement d'un émulateur pour une console de jeu vidéo.

Capture d'écran du jeu Space Invaders

![cover](https://github.com/YoiseauDesIles/Chip-8-Emulator/assets/122680880/47a1622e-bcd9-4968-9f82-44565246a721)

Capture d'écran du jeu Puissance 4

![connect4](https://github.com/YoiseauDesIles/Chip-8-Emulator/assets/122680880/3de6630f-ba0b-41c3-a828-ff28e163da29)


Voici comment jouer à des jeux sur la console : 
 - La "manette" de la Chip8 se compose de 16 touches : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F
 - Ces touches sont mappées sur le pavé numérique du clavier pour les touches 0 à 9, puis le reste correspond à sa propre touche du clavier (A, B, C, D, E, F)
 - L'émulateur charge des roms situées dans le dossier Roms en selectionnant le nom de la rom dans le fichier Cartrige.cpp



Pour faire fonctionner SDL pour le projet (Windows) : 

 - Creer la variable d'environnement CMAKE_PREFIX_PATH et y mettre le chemin d'accès vers la librairie SDL2_VS
 - En utilisant le compilateur mingw32 :  
    - donner le chemin d'accès a SDL : set(SDL2_DIR "C:/_Apps/SDL2_all/32/SDL2")
    - chercher le paquet SDL2 : find_package(SDL2 REQUIRED)
    - Inclure les en-tetes SDL2 : include_directories(${SDL2_INCLUDE_DIRS})
    - Après l'ajout des executables, Lier la bibliothèque SDL2 à l'executable : target_link_libraries(Chip8Emulator ${SDL2_LIBRARIES})

 - En utilisant le compilateur MSVC amd 64 :  
    - chercher le paquet SDL2 : find_package(SDL2 REQUIRED)
    - Après l'ajout des executables, Lier la bibliothèque SDL2 à l'executable : target_link_libraries(Chip8Emulator SDL2::SDL2 SDL2::SDL2main)

Dans le main, écrire int main(int argc, char **argv) pour que SDL puisse faire le lien avec SDL_main   

Ajouter la DLL correspondante au même niveau que l'éxecutable généré par Cmake

