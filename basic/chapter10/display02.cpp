//포인터 변수 기본 조작
#include<iostream>
using namespace std;

int main(void){
    int* p1;
    int* p2;

    p1 = new int;
    *p1 = 42;

    p2 = p1; //같은 곳을 가리키게 함

    cout << "*p1 : " << *p1 << endl; //42
    cout << "*p2 : " << *p2 << endl; //42

    *p2 = 53; //여전히 같은 곳을 가리키므로 *p1 또한 53

    cout << "*p1 : " << *p1 << endl; //53
    cout << "*p2 : " << *p2 << endl; //53
    
    p1 = new int; //p1이 새로운 곳을 가리킴
    *p1 = 88;

    cout << "*p1 : " << *p1 << endl; //88
    cout << "*p2 : " << *p2 << endl; //53

    return 0;
}