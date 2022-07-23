#pragma once
#include<iostream>
using namespace std;

#include "vertex.h"

class linkedlist{
    public:
        linkedlist();

        //insert
        void append(int itemv);
        //pop
        //remove
        int get(int index);
        //index
        //isempty
        //size
        //clear
        //count
        //extend
        //copy
        //reverse
        //sort

        void sneaky(void);
    private:
        vertex* dummy;
        int num; //배열 요소 개수

        friend class vertex;
};

linkedlist::linkedlist(){
    dummy = new vertex(-999);
    int num = 0;
}

void linkedlist::append(int itemv){
    vertex* vertexnew = new vertex(itemv);
    vertex* iter = dummy;

    for(int i = 0; i < num; i++){
        iter = (*iter).getnext();
        cout << (*iter).getitem() << endl;
    }

    *iter = *vertexnew;
    num += 1;
}
int linkedlist::get(int index){
    vertex* iter = (*dummy).getnext();

    for(int i = 0; i < index; i++){
        iter = (*iter).getnext();
    }

    return (*iter).getitem();
}

void linkedlist::sneaky(void){
    cout << (*dummy).getitem() << endl;
    cout << (*((*dummy).getnext())).getitem() << endl;
    cout << (*(*(*dummy).getnext()).getnext()).getitem() << endl;
}