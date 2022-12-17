#include <bits/stdc++.h>
#include "SDL2/SDL.h"


SDL_Event event;
SDL_Window *window;
SDL_Renderer *renderer;
bool gamerunning=true;

void Init(){
    SDL_Init(SDL_INIT_EVERYTHING);
    window=SDL_CreateWindow("testing purpos",10,30,1350,650,0);
    renderer=SDL_CreateRenderer(window,-1,0);
    SDL_SetRenderDrawColor(renderer,255,255,255,255);

}

void HandleEvent(){
    SDL_PollEvent(&event);
    switch(event.type){
        case SDL_QUIT:gamerunning=false;
            break;
    }
}

void Renderer(){
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

int main(int argc, char* argv[]){
    Init();
    /*
    Uint32 starttime;
    int framedelay=10;
    int frametime;
    while(gamerunning){
        starttime=SDL_GetTicks();
        HandleEvent();
        Renderer();
        frametime=starttime-SDL_GetTicks();
        if(frametime<framedelay){
            SDL_Delay(framedelay-frametime);
        }
    }
    Clean();
    */
    return 0;
}
