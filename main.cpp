#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include <SDL.h>
#endif

#include "Main.h"

#define LOGO_WIDTH 390
#define LOGO_HEIGHT 154
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_DEPTH 16

int main ( int argc, char** argv )
{
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(SCREEN_WIDTH, 480, 16,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // load an image
//    SDL_Surface* bmp = SDL_LoadBMP("logo.bmp");
//    if (!bmp)
//    {
//        printf("Unable to load bitmap: %s\n", SDL_GetError());
//        return 1;
//    }




Sprite* mySprite = new Sprite("dlogo.bmp",15,60);
mySprite->setTransparency(0,255,0);

Sprite** diablologo = new Sprite*[15];


for (int i = 0; i<= 15; i++)
{
    diablologo[i] = new Sprite(mySprite->getRect(0, 0, 0, 0), 15, 60);
}




    // centre the bitmap on screen
//    SDL_Rect dstrect;
//    dstrect.x = (screen->w - bmp->w) / 2;
//    dstrect.y = (screen->h - bmp->h) / 2;

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE

        // clear screen
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));


mySprite->animate()->draw(screen,(640/2)-(LOGO_WIDTH/2),(480/2)-(LOGO_HEIGHT/2));


        // draw bitmap
        //SDL_BlitSurface(bmp, 0, screen, &dstrect);

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(screen);
    } // end main loop

    // free loaded bitmap
    //SDL_FreeSurface(bmp);

    // all is well ;)
    //printf("Exited cleanly\n");
    return 0;
}
