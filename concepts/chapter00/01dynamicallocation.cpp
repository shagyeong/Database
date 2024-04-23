#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, char* argv[]){
    //포인터 변수 기본 개념
    cout << endl <<  "//" << endl;
    int v1;
    int* p1;

    v1 = 21;
    p1 = &v1;

    cout << "v1 : " << v1 << endl
         << "*p1 : " << *p1 << endl;

    //동적 변수
    cout << endl <<  "//" << endl;
    int* p2;
    p2 = new int;
    *p2 = 22;
    cout << "*p2 : " << *p2 << endl;
    
    delete p2;
    p2 = NULL;

    //동적 배열
    cout << endl <<  "//" << endl;
    int* p3;
    p3 = new int[3]{17, 22, 32};

    cout << "*p3 : " << *p3 << endl;
    cout << "*(++p3) : " << *(++p3) << endl;
    return 0;
}