#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

void DrawMap(int x,int y);

SDL_Texture *playertext;
SDL_Rect sr,dr;

#include <iostream>
#include "vector2D.h"
#include "ECS.h"

Manager manager;
Entity *newplayer=manager.AddEntity();

#include "PositionComponent.h"
#include "controller.h"
#include "spritecomponent.h"









#endif // GAME_H_INCLUDED
