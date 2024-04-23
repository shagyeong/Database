//다차원 배열 연습
#include<iostream>
using namespace std;

const int AXIS0 = 3;
const int AXIS1 = 7;
const int AXIS2 = 7;

int main(void){
    int array01[AXIS0][AXIS1] = {
        {14, 15, 16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25, 26, 27},
        {28, 29, 30, 31, 32, 33, 34}
    };

    int* p01 = &array01[0][0];

    for(int i = 0; i < 21 - 1; i++){
        cout << *p01 << " ";
        p01++;
    }

    return 0;
}