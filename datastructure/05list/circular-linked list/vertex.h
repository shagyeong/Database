#pragma once
#include<iostream>
using namespace std;

class vertex{
    public:
        vertex();
        vertex(int itemv);
        vertex(vertex* frontv, vertex* rearv, int itemv);
        vertex(const vertex& vertexv);

        vertex* getfront(void);
        vertex* getrear(void);
        int getitem(void);

        void setfront(vertex* frontv);
        void setrear(vertex* rearv);
        void setitem(int itemv);
    private:
        vertex* front;
        vertex* rear;
        int item;
};

vertex::vertex(){
    front = NULL;
    rear = NULL;
    item = -9999;
}
vertex::vertex(int itemv){
    front = NULL;
    rear = NULL;
    item = itemv;
}
vertex::vertex(vertex* frontv, vertex* rearv, int itemv){
    front = frontv;
    rear = rearv;
    item = itemv;
}
vertex::vertex(const vertex& vertexv){
    cout << "copyconstructor called" << endl;
    front = vertexv.front;
    rear = vertexv.rear;
    item = vertexv.item;
}

vertex* vertex::getfront(void){
    return front;
}
vertex* vertex::getrear(void){
    return rear;
}
int vertex::getitem(void){
    return item;
}

void vertex::setfront(vertex* frontv){
    front = frontv;
}
void vertex::setrear(vertex* rearv){
    rear = rearv;
}
void vertex::setitem(int itemv){
    item = itemv;
}