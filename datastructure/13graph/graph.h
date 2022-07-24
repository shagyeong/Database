//인접 리스트 클래스
#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "vertex.h"
#include "branch.h"

class graph{
    public:
        graph(string namev, vertex adjv[]);
        graph(const graph& graphv);

        string getname(void);
        vertex* getadj(void);

        void setname(string namev);
        void setadj(vertex adjv[]);

        void iter(vertex adjv[]); //정점 배열로 순회하기
    private:
        string name;
        vertex* adj; //첫 번째 요소의 포인터
};

graph::graph(string namev, vertex adjv[]){
    name = namev;
    adj = &(adjv[0]);
}
graph::graph(const graph& graphv){
    name = graphv.name;
    adj = graphv.adj;
}

string graph::getname(void){
    return name;
}
vertex* graph::getadj(void){
    return adj;
}

void graph::setname(string namev){
    name = namev;
}
void graph::setadj(vertex adjv[]){
    adj = &(adjv[0]);
}

//void iter(vertex adjv[]); //정점 배열로 순회하기