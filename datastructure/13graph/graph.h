//인접 리스트 클래스
#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "vertex.h"
#include "branch.h"

class graph{
    public:
        graph(string namev, vertex* adj[]);

        string getname(void);
        vertex* getadj(void);

        void setname(string namev);
        void setadj(vertex* adjv[]);

        void iter(vertex* adjv[]); //정점 배열로 순회하기
    private:
        string name;
        vertex* adj;
};