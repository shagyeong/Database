#pragma once
#include<iostream>
#include<string>
using namespace std;

class branch{
    public:
        branch();
        branch(string namev);
        branch(string namev, int lengthv);
        branch(const branch& branchv);

        string getname(void);
        int getlength(void);

        void setname(string namev);
        void setlength(int lengthv);
    private:
        string name;
        int length;

        friend class vertex;
        friend class graph;
};

branch::branch(){
    name = "no named branch";
    length = 0;
}
branch::branch(string namev){
    name = namev;
    length = 0;
}
branch::branch(string namev, int lengthv){
    name = namev;
    length = lengthv;
}
branch::branch(const branch& branchv){
    name = branchv.name;
    length = branchv.length;
}

string branch::getname(void){
    return name;
}
int branch::getlength(void){
    return length;
}

void branch::setname(string namev){
    name = namev;
}
void branch::setlength(int lengthv){
    length = lengthv;
}