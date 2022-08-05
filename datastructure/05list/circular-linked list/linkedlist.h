#pragma once
#include<iostream>
#include<cstdlib>
#include "./vertex.h"
using namespace std;

class linkedlist{
    public:
        linkedlist();
        void append(int item);
        //insert 
        int pop(void);
        //remove
        //get 
        //index 
        //isempty
        //size
        //cleanse
        //count
        //extend
        //copy
        //reverse
        //sort

        void sneaky(void); //오류 테스트 멤버 함수
        void iterate(void); //모든 요소를 출력
    private:
        vertex* dummy;
        int num;
};

linkedlist::linkedlist(){
    dummy = new vertex;
    dummy->setfront(dummy);
    dummy->setrear(dummy);
    num = 0;
}

void linkedlist::append(int item){
    vertex* newvertex = new vertex(item);
    
    dummy->getfront()->setrear(newvertex);
    dummy->setfront(newvertex);

    newvertex->setfront(dummy->getfront());
    newvertex->setrear(dummy);

    num += 1;
}
//insert 
int linkedlist::pop(void){
    if(num == 0){
        cout << "cannot pop dummy vertex" << endl;
        exit(1);
    }
    else{
        int popitem;
        vertex* iter = dummy->getfront();
        popitem = iter->getitem();

        dummy->setfront(iter->getfront());
        iter->getfront()->setrear(dummy);

        num -= 1;
        return popitem;
    }
}
//remove
//get 
//index 
//isempty
//size
//cleanse
//count
//extend
//copy
//reverse
//sort

//void sneaky(void); //오류 테스트 멤버 함수
void linkedlist::iterate(void){
    vertex* iter = dummy;

    for(int i = 0; i < num; i++){
        iter = iter->getrear();
        cout << iter->getitem() << " ";
    }

    cout << endl;
}