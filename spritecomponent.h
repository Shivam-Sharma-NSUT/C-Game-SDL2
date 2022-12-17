#ifndef SPRITECOMPONENT_H_INCLUDED
#define SPRITECOMPONENT_H_INCLUDED
#include "Map.h"

class spritecomponent:public Component{
public:
    spritecomponent(const char* path){
        texture=SDL_CreateTextureFromSurface(renderer,IMG_Load("assets/testing.png"));
        dr.x=600;
        dr.y=300;
        dr.h=dr.w=64;
        sr.x=sr.y=0;
        sr.h=sr.w=100;
    }
    ~spritecomponent(){}
    void init(){
    }
    void update(){
        std::cout<<"updating";
        static int flag=0;
        while(flag++%15==0){
            if(sr.x==100)
                sr.x=0;
            else sr.x=100;
        }
    }
    void draw(){
        std::cout<<dr.x<<","<<dr.y<<"\n";
        SDL_RenderCopy(renderer,texture,&sr,&dr);
    }
    void Setsprite(int x,int y){
        dr.x=x;
        dr.y=y;
    }
private:
    SDL_Texture *texture;
    SDL_Rect sr,dr;
};


#endif // SPRITECOMPONENT_H_INCLUDED
