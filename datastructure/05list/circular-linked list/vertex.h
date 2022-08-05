#pragma once
#include<iostream>
using namespace std;

class vertex{
    public:
        vertex();
        vertex(vertex* frontv, vertex* rearv, int itemv);
    private:
        vertex* front;
        vertex* rear;
        int item;
};