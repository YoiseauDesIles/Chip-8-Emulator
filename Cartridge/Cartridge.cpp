#include "Cartridge.h"

Cartridge::Cartridge() 
{
    for (auto &i : programData)
        i = 0x00;
    // programData[0] = 0x60;  //0x200 
    // programData[1] = 0x0F;
    // programData[2] = 0xF0;  //0x202 
    // programData[3] = 0x29;
    // programData[4] = 0xD1;  //0x204
    // programData[5] = 0x25;
    // programData[6] = 0x12;  //0x206   
    // programData[7] = 0x06;
    // programData[8] = 0xA0;  //0x208  
    // programData[9] = 0x00;
    // programData[10] = 0x12;  //0x20A  
    // programData[11] = 0x00;

    parseGameData();
}

uint8_t Cartridge::parseGameData()
{
    FILE *jeu=NULL; 
    jeu=fopen("roms/TANK","rb"); 

    if(jeu!=NULL) 
    { 
        fread(&programData[0],3232, 1, jeu); 
        fclose(jeu); 
        printCartrigde();
        return 1; 
    } 
    else 
    { 
      fprintf(stderr,"Problème d'ouverture du fichier"); 
      return 0; 
    } 

    // std::ifstream file("game.txt", std::ios::binary);
    // if (!file)
    // {
    //     std::cout << "impossible de d'ouvrir le fichier" << "\n";
    //     return -1;
    // }else
    // std::cout << "succes de la lecture du fichier game.txt" << "\n";


    // file.read(programData2.data(), 3232);
    
    // file.close();

    // printCartrigde();
    // return 1;
    
    int x;
    uint8_t y;
    std::ifstream inFile;
    inFile.open("game.txt");
    if (!inFile) 
    {
        std::cerr << "Impossible d'ouvrir le fichier" << "\n";
        return -1;
    }
    uint8_t count = 0;
    uint8_t chars = 0;
    while (inFile >> x)
    {   
        // if (count % 2 == 1)
        // {
        //     chars = (chars << 4) + x;

        //     std::cout << "Char impair : " << std::hex << chars+0 << " ";
        //     programData[(count-1)/2] = chars;
        //     chars = 0;
        // } else
        // {
        //     chars = x;
        //     std::cout << "Char pair : " << std::hex << chars+0 << " ";

        // }
        programData[count] = x;
        count++;
    }

    inFile.close();
    printCartrigde();

    return 1;

}


void Cartridge::printCartrigde() const 
{
    std::cout << "\n";
    for (const uint8_t& codeHexa : programData)
    {
        std::cout << std::hex << codeHexa+0 << " ";
    }
}