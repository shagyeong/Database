//배열 정렬 예제
//swap에서 개별 요소를 단순 변수 처럼 다루는 것을 확인하라
#include<iostream>
using namespace std;

const int SIZE = 20;

void fillarray(int array[], int& numberused);
void sort(int array[], int& numberused);
void swap(int& v1, int& v2);
int minindex(const int array[], int startindex, int numberused);

int main(void){
    int array[SIZE];
    int numberused;

    fillarray(array, numberused);

    sort(array, numberused);

    cout << "sorted array\n";
    for(int index = 0; index < numberused; index++){
        cout << array[index] << " ";
    }
    cout << endl;

    return 0;
}


void fillarray(int array[], int& numberused){
    int index = 0;
    int element;

    cout <<  "fill array up to " << SIZE << endl;
    cout << "negative number == end of input" << endl;

    cin >> element;

    while((index < SIZE) && (element > 0)){
        array[index] = element;
        cin >> element;

        index++;
    }

    numberused = index;
}
void sort(int array[], int& numberused){
    int minindex2;

    for(int index = 0; index < numberused - 1; index++){
        minindex2 = minindex(array, index, numberused);
        swap(array[index], array[minindex2]);
    }
}
void swap(int& v1, int& v2){
    int temp;

    temp = v1;
    v1 = v2;
    v2 = temp;
}
int minindex(const int array[], int startindex, int numberused){
    int min = array[startindex];
    int minindex = startindex;

    for(int index = startindex; index < numberused; index++){
        if(array[index + 1] < min){
            min = array[index + 1];
            minindex = index + 1;
        }
    }

    return minindex;
}
