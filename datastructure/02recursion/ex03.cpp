//ch02*실습.pdf의 연습문제
//2^n을 구하는 함수를 재귀적으로 작성

#include<iostream>
using namespace std;

int pow2(int n);

int main(void){
    cout << pow2(2) << endl;
    cout << pow2(10) << endl;

    return 0;
}

int pow2(int n){
    if(n == 0){
        return 1;
    }
    else{
        return pow2(n - 1) * 2;
    }
}