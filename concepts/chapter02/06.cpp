//while 예제
#include<iostream>
using namespace std;

int main(void){
    int noi; //number of item
    int count;
    int cfi; //calories for item
    int tc; //total calories

    cout << "how many items did you eat today? : ";
    cin >> noi;

    tc = 0;
    count = 0;

    cout << "enter each calories of " << noi << " items" << endl;

    while(count ++ < noi){
        cin >> cfi;
        tc += cfi;
    }

    cout << "total calories : " << tc << endl;

    return 0;
}