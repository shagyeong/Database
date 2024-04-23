//값 호출에서 포인터 변수를 인수로 전달
//지역 사본에 대한 변화가 실제 변화로 이어지는 위험성 확인
#include<iostream>
using namespace std;

void sneaky(int* p0);

int main(void){
    int* p1;
    p1 = new int;
    *p1 = 77;

    cout << "*p1 before function call : " << *p1 << endl;
    sneaky(p1);
    cout << "*p1 after function call : " << *p1 << endl;

    return 0;
}

void sneaky(int* p0){
    *p0 = 99;
    cout << "*pointer in function call : " << *p0 << endl;
}