//ch02*실습.pdf의 연습문제
//등차수열의 n번쨰 항을 구하는 함수를 재귀적으로 작성

#include<iostream>
using namespace std;

class aseries{
    public:
        //생성자
        aseries();
        aseries(int a1value, int dvalue);
        //멤버 변수
        int a1;
        int d;
        //멤버 메서드
        int an(int n);
};

//생성자
aseries::aseries(){
    a1 = 1;
    d = 1;
}
aseries::aseries(int a1value, int dvalue){
    a1 = a1value;
    d = dvalue;
}
//멤버 메서드
int aseries::an(int n){
    if(n == 1){
        return a1;
    }
    else{
        return an(n - 1) + d;
    }
}

int main(void){
    aseries as1(3, 3);

    cout << as1.an(7) << endl;

    return 0;
}

//상수만으로 해결
/*
#define A1 1
#define D  1
...
*/