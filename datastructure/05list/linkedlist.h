#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

#include "vertex.h"

class linkedlist{
    public:
        linkedlist();

        void append(int itemv);
        void insert(int index, int itemv);
        int pop(void);
        void remove(int index);
        int get(int index);
        int index(int itemv); //아이템이 몇 번째 인덱스인지 반환
        bool isempty(void);
        int size(void);
        void cleanse(void); //모든 요소 삭제
        int count(int itemv);
        //extend
        //copy
        //reverse
        //sort

        void sneaky(void); //오류 테스트 멤버 함수
        void iterate(void); //모든 요소를 출력
    private:
        vertex* dummy;
        int num; //배열 요소 개수

        friend class vertex;
};

linkedlist::linkedlist(){
    dummy = new vertex(-999);
    num = 0;
}

void linkedlist::append(int itemv){
    vertex* vertexnew = new vertex(itemv);
    vertex* iter = dummy;

    while((*iter).getnext() != NULL){
        iter = (*iter).getnext();
    }

    (*iter).setnext(vertexnew);
    num += 1;
}
void linkedlist::insert(int index, int itemv){
    if(index > num){
        cout << "invalid index" << endl;
        exit(1);
    }
    else{
        if(index == num){
            append(itemv); //순환형이 아니므로 마지막 위치에 삽입일 경우 코드가 복잡해짐
        }
        else{
            vertex* vertexnew = new vertex(itemv);
            vertex* iter1 = dummy; //삽입 위치 바로 앞의 정점
            vertex* iter2; //삽입 위치 바로 뒤의 정점

            for(int i =0; i < index; i++){
                iter1 = (*iter1).getnext();
            }
            iter2 = (*iter1).getnext();
            (*vertexnew).setnext(iter2);
            
            (*iter1).setnext(vertexnew);
            num += 1;
        }
    }
}
int linkedlist::pop(void){
    if(num == 0){
        cout << "cannot pop dummy vertex" << endl;
        exit(1);
    }
    else{
        vertex* iter = dummy;

        for(int i = 0; i < num - 1; i++){
            iter = (*iter).getnext();
        }

        int popitem = (*((*iter).getnext())).getitem();
        (*iter).setnext(NULL);

        num -= 1;
        return popitem;
    }
}
void linkedlist::remove(int index){
    if(index > num - 1){
        cout << "invalid index" << endl;
        exit(1);
    }
    else{
        if(index == num - 1){
            pop(); //순환형이 아니므로 마지막 요소를 삭제할 경우 코드가 복잡해짐
        }
        else{
            vertex* iter1 = dummy; //삭제 위치 바로 앞의 정점
            vertex* iter2; //삭제 위치 바로 뒤의 정점

            for(int i =0; i < index - 1; i++){
                iter1 = (*iter1).getnext();
            }
            iter2 = (*iter1).getnext();
            iter2 = (*iter2).getnext();

            (*iter1).setnext(iter2);
            num -= 1;
        }
    }
}
int linkedlist::get(int index){
    vertex* iter = (*dummy).getnext();

    for(int i = 0; i < index; i++){
        iter = (*iter).getnext();
    }

    return (*iter).getitem();
}
int linkedlist::index(int itemv){
    vertex* iter = dummy;
    int index = -1;

    do{
        index += 1;
        iter = (*iter).getnext();

        if((*iter).getitem() == itemv){
            return index;
        }
    }while((*iter).getnext() != NULL);

    cout << "the element is not in the list" << endl;
    exit(1);
}
bool linkedlist::isempty(void){
    return (num == 0);
}
int linkedlist::size(void){
    return num;
}
void linkedlist::cleanse(void){
    (*dummy).setnext(NULL);
    num = 0;
}
int linkedlist::count(int itemv){
    vertex* iter = dummy;
    int itemnum = 0; //검색 요소 개수

    while((*iter).getnext() != NULL){
        iter = (*iter).getnext();

        if((*iter).getitem() == itemv){
            itemnum += 1;
        }
    }

    return itemnum;
}
//extend
//copy
//reverse
//sort

void linkedlist::sneaky(void){
    cout << "sneaky test" << endl;
}
void linkedlist::iterate(void){
    cout << "the number of elements : " << num << endl;

    vertex* iter = dummy;

    //요소 개수가 0일 경우 NULL의 아이템에 접근하므로 에러
    //요소 개수가 1 이상인 경우만 순회
    if(num != 0){
        do{
            iter = (*iter).getnext();
            cout << (*iter).getitem() << " "; //에러
        }while((*iter).getnext() != NULL);
    }

    cout << endl;
}