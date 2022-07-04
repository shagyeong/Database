//ch02*실습.pdf의 연습문제
//n개 고리-하노이탑 풀이과정을 재귀적으로 출력하는 프로그램 작성

#include<iostream>
using namespace std;

void hanoi(int n, const char* depart, const char* sub, const char* dest);

int main(void){
    cout << "4 rings" << endl;
    hanoi(4, "a", "b", "c");

//    cout << "10 rings" << endl;
//    hanoi(10, "a", "b", "c");

    return 0;
}

void hanoi(int n, const char* depart, const char* sub, const char* dest){
    if(n >= 2){
        hanoi(n - 1, depart, dest, sub);
    }
    cout << "move " << n
         << " from " << *depart 
         << " to " << *dest
         << endl;
    if(n >= 2){
        hanoi(n - 1, sub, depart, dest);
    }
}

