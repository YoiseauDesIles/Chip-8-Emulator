# emulateur-nul

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

