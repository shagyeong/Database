//호출 메커니즘 비교 예제
//참조 호출로 인수에 직접 접근해 swap
//*참고 : 원본의 04-02와 04-04가 같음
#include<iostream>
using namespace std;

void getnumbers(int& i1, int& i2); //i : input
void swapvalues(int& v1, int& v2);
void showresults(int output1, int output2);

int main(void){
    int num1;
    int num2;

    getnumbers(num1, num2);
    swapvalues(num1, num2);
    showresults(num1, num2);

    return 0;
}

void getnumbers(int& i1, int& i2){
    cout << "enter two integers" << endl;
    cin >> i1;
    cin >> i2;
}
void swapvalues(int& v1, int& v2){
    int temp;
    temp = v1;
    v1 = v2;
    v2 = temp;
}
void showresults(int output1, int output2){
    cout << "numbers reversed" << endl;
    cout << "output1 : " << output1 << endl;
    cout << "output2 : " << output2 << endl;
}
