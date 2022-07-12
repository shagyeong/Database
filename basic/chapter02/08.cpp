//브레이크문 예제
#include<iostream>
using namespace std;

int main(void){
    int number;
    int sum = 0;
    int count = 0;

    cout << "enter 4 positive numbers : " << endl;

    while(count++ < 4){
        cin >> number;
        
        if(number <= 0){
            cout << "error : negative number or 0 entered" << endl;
            break;
        }

        sum += number;
    }

    cout << "summed numbers : " << count - 1 << endl;
    cout << "sum : " << sum << endl;

    return 0;
}