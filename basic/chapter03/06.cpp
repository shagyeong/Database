//타입캐스트, 사용자 정의 함수 예제
#include<iostream>
#include<cmath>
using namespace std;

int round2(double dvalue);
//0이상의 실수가 입력됨을 가정
//가장 가까운 정수를 반환

int main(void){
    double d1;
    char answer;

    do{
        cout << "enter a double value : ";
        cin >> d1;

        cout << "rounded number is : "
             << round2(d1)
             << endl;
        
        cout << "again?(y/n) : ";
        cin >> answer;
    }while(answer == 'y' || answer == 'Y');

    return 0;
}

int round2(double dvalue){
    return static_cast<int>(floor(dvalue + 0.5));
}