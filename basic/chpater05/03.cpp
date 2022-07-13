//배열 매개변수 예제
#include<iostream>
using namespace std;

void fillup(int arr[], int arrsize);

int main(void){
    const int ARRSIZE_A1 = 5;
    const int ARRSIZE_A2 = 10;

    int a1[ARRSIZE_A1];
    int a2[ARRSIZE_A2];

    fillup(a1, ARRSIZE_A1);
    fillup(a2, ARRSIZE_A2);

    return 0;
}

void fillup(int arr[], int arrsize){
    cout << "hello\n";
    cout << "enter "
         << arrsize
         << " elements" << endl;
    
    for(int i = 0; i < arrsize; i++){
        cin >> arr[i];
    }

    cout << "last index : " << arrsize - 1 << endl;
}