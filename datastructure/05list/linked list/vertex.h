#pragma once
#include<iostream>
using namespace std;

class vertex{
    public:
        vertex();
        vertex(int itemv);
        vertex(int itemv, vertex* nextv);
        vertex(const vertex& vertexv);
        
        int getitem(void);
        vertex* getnext(void);

        void setitem(int newitem);
        void setnext(vertex* newnext);
    private:
        int item;
        vertex* next;
        
        friend class linkedlist;
};

vertex::vertex(){
    item = -9999;
    next = NULL;
}
vertex::vertex(int itemv){
    item = itemv;
    next = NULL;
}
vertex::vertex(int itemv, vertex* nextv){
    item = itemv;
    next = nextv;
}
vertex::vertex(const vertex& vertexv){
    cout << "copy constructor called" << endl;
    item = vertexv.item;
    next = vertexv.next;
}

int vertex::getitem(void){
    return item;
}
vertex* vertex::getnext(void){
    return next;
}

void vertex::setitem(int newitem){
    item = newitem;
}
void vertex::setnext(vertex* newnext){
    next = newnext;
}