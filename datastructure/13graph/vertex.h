#pragma once
#include<iostream>
#include<string>
using namespace std;

class vertex{
    public:
        vertex();
        vertex(string namev);
        vertex(const vertex& vertexv);

        string getname(void);
        void setname(string namev);     
    private:
        string name;

        friend class branch;
        friend class graph;
};

vertex::vertex(){
    name = "no named vertex";
}
vertex::vertex(string namev){
    name = namev;
}
vertex::vertex(const vertex& vertexv){
    name = vertexv.name;
}

string vertex::getname(void){
    return name;
}
void vertex::setname(string namev){
    name = namev;
}