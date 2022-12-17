#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#define maxsize 32
#define comp Component*

class Entity;

int id=0;

class Component{
public:
    Entity *entity;
    Component(){}
    ~Component(){}
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}
};

class Entity{
private:
    bool active;
    bool List[maxsize];
    std::vector<comp> components;
public:
    Entity(){active=true;}
    ~Entity(){}

    template<typename T> T* GetComp(int i){
        return (T*)components[i];
    }

    template<typename T> T* AddComp(){
        std::cout<<"adding component\n";
        T *c=new T;
        std::cout<<"T *c=new T;\n";
        c->entity=this;
        std::cout<<"c->entity=this;\n";
        components.push_back(c);
        std::cout<<"components.push_back(c);\n";
        List[id++]=true;
        std::cout<<"List[id++]=true;\n";
        c->init();
        std::cout<<"c->init();\n";
        return c;
    }

    template<typename T> T* AddComp(const char* path){
        T *c=new T(path);
        std::cout<<"T *c=new T(path);\n";
        c->entity=this;
        components.push_back(c);
        List[id++]=true;
        c->init();
        std::cout<<"c->init();\n";
        return c;
    }

    void init(){}

    void update(){
        for(unsigned int i=0;i<components.size();i++) components[i]->update();
    }

    void draw(){
        for(unsigned int i=0;i<components.size();i++) components[i]->draw();
    }

    inline bool IsActive(){ return active; }
    inline void destroy(){ active=false; }
 };

class Manager{
private:
    std::vector<Entity*> entities;
public:
    Manager(){}
    ~Manager(){}
    Entity* AddEntity(){
        Entity *entity=new Entity;
        entities.push_back(entity);
        return entity;
    }
    void update(){
        std::cout<<"manager updating\n";
        for(unsigned int i=0;i<entities.size();i++) entities[i]->update();
        std::cout<<"manager is updated\n";
    }
    void draw(){
        for(unsigned int i=0;i<entities.size();i++) {entities[i]->draw();
        }
    }
    /*void refresh(){
        for(unsigned int i=0;i<entities.size();i++){
            std::remove_if(!entities[i]->IsActive())
        }
    }*/
 };



#endif // ECS_H_INCLUDED
