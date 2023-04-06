#include "Controller.h"


uint8_t Controller::updateInputState(std::array<uint8_t, 16> & keys) const
{
    uint8_t continueGame = 1;

    SDL_Event event2;
    try {

        while( SDL_PollEvent(&event2)) 
    { 
                    switch(event2.type) 
                    { 
                        case SDL_QUIT: {continueGame = 0;break;} 
                        case SDL_KEYDOWN:{ 
                                            switch(event2.key.keysym.scancode) 
                                            { 
                                                case SDL_SCANCODE_KP_0:{   std::cout << "0 pressed \n"; keys[0x0] = 1; break;} 
                                                case SDL_SCANCODE_KP_1:{   keys[0x1] = 1; break;} 
                                                case SDL_SCANCODE_KP_2:{   keys[0x2] = 1; break;}
                                                case SDL_SCANCODE_KP_3:{   keys[0x3] = 1; break;}
                                                case SDL_SCANCODE_KP_4:{   keys[0x4] = 1; break;}
                                                case SDL_SCANCODE_KP_5:{   keys[0x5] = 1; break;}
                                                case SDL_SCANCODE_KP_6:{   keys[0x6] = 1; break;}
                                                case SDL_SCANCODE_KP_7:{   keys[0x7] = 1; break;}
                                                case SDL_SCANCODE_KP_8:{   keys[0x9] = 1; break;}
                                                case SDL_SCANCODE_KP_9:{   keys[0x9] = 1; break;}
                                                case SDL_SCANCODE_A:   {   std::cout << "A pressed \n";  keys[0xA] = 1; break;}
                                                case SDL_SCANCODE_B:   {   keys[0xB] = 1; break;}
                                                case SDL_SCANCODE_C:   {   keys[0xC] = 1; break;}
                                                case SDL_SCANCODE_D:   {   keys[0xD] = 1; break;}
                                                case SDL_SCANCODE_E:   {   keys[0xE] = 1; break;}
                                                case SDL_SCANCODE_F:   {   keys[0xF] = 1; break;}
                                                 
                                                /*
                                                  Et toutes les autres touches
                                                */ 
                                                default:{ break;} 
                                            } ;break;} 
                            case SDL_KEYUP:{ 
                                            switch(event2.key.keysym.scancode) 
                                            { 
                                                case SDL_SCANCODE_KP_0:{  keys[0x0] = 0; break;} 
                                                case SDL_SCANCODE_KP_1:{  keys[0x1] = 0; break;} 
                                                case SDL_SCANCODE_KP_2:{  keys[0x2] = 0; break;} 
                                                case SDL_SCANCODE_KP_3:{  keys[0x3] = 0; break;} 
                                                case SDL_SCANCODE_KP_4:{  keys[0x4] = 0; break;} 
                                                case SDL_SCANCODE_KP_5:{  keys[0x5] = 0; break;} 
                                                case SDL_SCANCODE_KP_6:{  keys[0x6] = 0; break;} 
                                                case SDL_SCANCODE_KP_7:{  keys[0x7] = 0; break;} 
                                                case SDL_SCANCODE_KP_8:{  keys[0x8] = 0; break;} 
                                                case SDL_SCANCODE_KP_9:{  keys[0x9] = 0; break;} 
                                                case SDL_SCANCODE_A:   {  std::cout << "A released \n"; keys[0xA] = 0; break;} 
                                                case SDL_SCANCODE_B:   {  keys[0xB] = 0; break;} 
                                                case SDL_SCANCODE_C:   {  keys[0xC] = 0; break;} 
                                                case SDL_SCANCODE_D:   {  keys[0xD] = 0; break;} 
                                                case SDL_SCANCODE_E:   {  keys[0xE] = 0; break;} 
                                                case SDL_SCANCODE_F:   {  keys[0xF] = 0; break;} 
                                                default:{ break;} 
                                            } ;break;} 

                        default:{ break;} 
                    } 

     } 
    } catch (std::exception &e)
    {
      std::cout << "exception update keys \n"; 
    }

    std::cout << "update keys \n";
    

     return continueGame;
     
}

uint8_t Controller::waitForInput(Registry & registry, std::array<uint8_t, 16> & keys, uint8_t XRegistry) const
{
    SDL_FlushEvents(SDL_FIRSTEVENT, SDL_LASTEVENT);
    SDL_Event event2;
    Uint8 attend=1,continuer=1; 

    std::cout << "wait for input \n";
    while(attend) 
    { 
        SDL_WaitEvent(&event2); 
        std::cout << "wait event passed \n";
        std::cout << "Event : " << event2.type << "\n";
            switch(event2.type) 
            { 
                case SDL_QUIT:{ 
                  continuer=0;
                  attend=0; 
                  break;} 

                case SDL_KEYDOWN:{ 

                    switch(event2.key.keysym.scancode) 
                    { 

                                                case SDL_SCANCODE_KP_0:{registry.setRegistry(XRegistry, 0x0);  keys[0x0] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_1:{registry.setRegistry(XRegistry, 0x1);  keys[0x1] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_2:{registry.setRegistry(XRegistry, 0x2);  keys[0x2] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_3:{registry.setRegistry(XRegistry, 0x3);  keys[0x3] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_4:{registry.setRegistry(XRegistry, 0x4);  keys[0x4] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_5:{registry.setRegistry(XRegistry, 0x5);  keys[0x5] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_6:{registry.setRegistry(XRegistry, 0x6);  keys[0x6] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_7:{registry.setRegistry(XRegistry, 0x7);  keys[0x7] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_8:{registry.setRegistry(XRegistry, 0x8);  keys[0x8] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_9:{registry.setRegistry(XRegistry, 0x9);  keys[0x9] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_A:   {registry.setRegistry(XRegistry, 0xA);  keys[0xA] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_B:   {registry.setRegistry(XRegistry, 0xB);  keys[0xB] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_C:   {registry.setRegistry(XRegistry, 0xC);  keys[0xC] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_D:   {registry.setRegistry(XRegistry, 0xD);  keys[0xD] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_E:   {registry.setRegistry(XRegistry, 0xE);  keys[0xE] = 1; attend = 0; break;} 
                                                case SDL_SCANCODE_F:   {registry.setRegistry(XRegistry, 0xF);  keys[0xF] = 1; attend = 0; break;} 
                                                default:{break;} 

                    } break;}
                  case SDL_KEYUP:{ 
                                          switch(event2.key.keysym.scancode) 
                                          { 
                                                case SDL_SCANCODE_KP_0:{registry.setRegistry(XRegistry, 0x0);  keys[0x0] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_1:{registry.setRegistry(XRegistry, 0x1);  keys[0x1] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_2:{registry.setRegistry(XRegistry, 0x2);  keys[0x2] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_3:{registry.setRegistry(XRegistry, 0x3);  keys[0x3] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_4:{registry.setRegistry(XRegistry, 0x4);  keys[0x4] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_5:{registry.setRegistry(XRegistry, 0x5);  keys[0x5] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_6:{registry.setRegistry(XRegistry, 0x6);  keys[0x6] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_7:{registry.setRegistry(XRegistry, 0x7);  keys[0x7] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_8:{registry.setRegistry(XRegistry, 0x8);  keys[0x8] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_KP_9:{registry.setRegistry(XRegistry, 0x9);  keys[0x9] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_A:   {registry.setRegistry(XRegistry, 0xA);  keys[0xA] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_B:   {registry.setRegistry(XRegistry, 0xB);  keys[0xB] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_C:   {registry.setRegistry(XRegistry, 0xC);  keys[0xC] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_D:   {registry.setRegistry(XRegistry, 0xD);  keys[0xD] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_E:   {registry.setRegistry(XRegistry, 0xE);  keys[0xE] = 0; attend = 0; break;} 
                                                case SDL_SCANCODE_F:   {registry.setRegistry(XRegistry, 0xF);  keys[0xF] = 0; attend = 0; break;} 
                                                /* ;
                                                  Et toutes les autres touches 
                                                */ 
                                                default:{break;} 
                                          }; break;}  

          default:{ break;} 
      } 
      
    } 

  
 return continuer; 

}
