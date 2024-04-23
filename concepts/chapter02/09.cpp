//컨티뉴 예제
//잔여 본문을 건너뛰어 조건식이 증가하지 않음을 확인하라
#include<iostream>
using namespace std;

int main(void){
    int number;
    int sum = 0;
    int count = 0;

    cout << "enter 4 positive numbers : " << endl;

    while(count < 4){
        cin >> number;
        
        if(number <= 0){
            cout << "error : negative number or 0 entered" << endl;
            cout << "\'re-enter\' the number and continue" << endl;
            continue;
        }

        sum += number;
        count += 1;
    }

    cout << "summed numbers : " << count << endl;
    cout << "sum : " << sum << endl;

    return 0;
}