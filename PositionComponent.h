#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED

#include "spritecomponent.h"
enum {
    POSITION,SPRITE,CONTROL,COLLIDE
};

class PosComp : public Component{
public:
    vector2D pos;
    vector2D vel;
    vector2D camera;
    int speed;
    spritecomponent *sprite;

    int x(){return pos.x;}
    int y(){return pos.y;}

    void init() {
        sprite=this->entity->GetComp<spritecomponent>(SPRITE);
        pos.x=400;
        pos.y=250;
        speed=5;
        vel.x=0;
        vel.y=0;
        camera.x=600;
        camera.y=300;
    }

    void update() {
        std::cout<<"updating Position\n";
        pos.x+=speed*vel.x;
        pos.y+=speed*vel.y;
        std::cout<<"pos is set\n";
        //if(pos.x>1350)pos.x=0;
        //if(pos.y>700)pos.y=0;
        std::cout<<"Position is adjusted\n";
        //this->entity->GetComp<spritecomponent>(SPRITE)->Setsprite(pos.x,pos.y);
        std::cout<<"Position is updated\n";
    }

    void setpos(int x,int y){
        pos.x=x;
        pos.y=y;
    }
    void draw(){
        DrawMap(pos.x,pos.y);
    }
    void setvel(int x,int y){
        vel.x=x;
        vel.y=y;
    }
};


#endif // POSITIONCOMPONENT_H_INCLUDED
