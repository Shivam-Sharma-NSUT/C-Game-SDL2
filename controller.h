#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED

class Controller : public Component{
private:
    PosComp *pos;
public:
    Controller(){
        pos = newplayer->GetComp<PosComp>(POSITION);
        std::cout<<pos->x()<<","<<pos->y();
    }
    void update() {
        if(event.type==SDL_KEYDOWN){
                std::cout<<"Key is Pressed\n";
            switch(event.key.keysym.sym){
                case SDLK_w:pos->setvel(0,-1);
                            break;
                case SDLK_s:pos->setvel(0,1);
                            break;
                case SDLK_a:pos->setvel(-1,0);
                            break;
                case SDLK_d:pos->setvel(1,0);
                            break;
                case SDLK_ESCAPE:gamerunning=false;
                case SDLK_w+SDLK_d:pos->setvel(1,1);
                            break;
            }
        }
        if(event.type==SDL_KEYUP)
            pos->setvel(0,0);
    }
    void draw() {}
};



#endif // CONTROLLER_H_INCLUDED
