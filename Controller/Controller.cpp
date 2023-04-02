#include "Controller.h"


uint8_t Controller::updateInputState(std::array<uint8_t, 16> & keys) const
{
    uint8_t continueGame = 1;

    while( SDL_PollEvent(event)) 
   { 
                    switch(event->type) 
                    { 
                        case SDL_QUIT: {continueGame = 0;break;} 
                        case SDL_KEYDOWN:{ 
                                            switch(event->key.keysym.scancode) 
                                            { 
                                                case SDL_SCANCODE_KP_0:{  std::cout << "scancode0 \n"; break;} 
                                                case SDL_SCANCODE_KP_1:{  std::cout << "scancode1 \n"; break;} 
                                                case SDL_SCANCODE_KP_2:{  std::cout << "scancode2 \n";break;} 
                                                /*
                                                  Et toutes les autres touches
                                                */ 
                                                default:{ std::cout << "default keydown \n"; break;} 
                                            } ;break;} 
                            case SDL_KEYUP:{ 
                                            switch(event->key.keysym.scancode) 
                                            { 
                                                case SDL_SCANCODE_KP_0:{  std::cout << "scancode0 \n";break;} 
                                                case SDL_SCANCODE_KP_1:{  std::cout << "scancode1 \n";break;} 
                                                case SDL_SCANCODE_KP_2:{  std::cout << "scancode2 \n";break;} 
                                                 /* 
                                                   Et toutes les autres touches 
                                                 */ 
                                                default:{ std::cout << "default keyup \n"; break;} 
                                            } ;break;} 

                        default:{ ; break;} 
                    } 

     } 

     return continueGame;
     
}

uint8_t Controller::waitForInput() const
{
    std::cout << "test";
    SDL_Event event2;
    Uint8 attend=1,continuer=1; 

    while(attend) 
    { 
        SDL_WaitEvent(&event2); 

            switch(event2.type) 
            { 
                case SDL_QUIT:{ continuer=0;attend=0; break;} 

                case SDL_KEYDOWN:{ 

                    switch(event2.key.keysym.scancode) 
                    { 

                                                case SDL_SCANCODE_KP_0:{  std::cout << "scancode0 \n";attend=0; break;} 
                                                case SDL_SCANCODE_KP_1:{  std::cout << "scancode1 \n";attend=0; break;} 
                                                case SDL_SCANCODE_KP_2:{  std::cout << "scancode2 \n"; attend=0;break;} 
                                                default:{ std::cout << "defualt keydown \n"; break;} 
                    } break;}
                  case SDL_KEYUP:{ 
                                          switch(event2.key.keysym.scancode) 
                                          { 
                                                case SDL_SCANCODE_KP_0:{  std::cout << "scancode0 keyup \n";attend=0; break;} 
                                                case SDL_SCANCODE_KP_1:{  std::cout << "scancode1 keyup\n"; attend=0; break;} 
                                                case SDL_SCANCODE_KP_2:{  std::cout << "scancode2 keyup\n"; attend=0;break;} 
                                                /* 
                                                  Et toutes les autres touches 
                                                */ 
                                                default:{ std::cout << "default keyup \n"; break;} 
                                          } ;break;}  

          default:{ std::cout << "default \n";break;} 
      } 
      
    } 

  
 return continuer; 

}
