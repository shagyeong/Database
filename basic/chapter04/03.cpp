//값 호출의 지역적 변경 예제
#include<iostream>
using namespace std;

void f1(int v1, int v2);

int main(void){
    int n1 = 11;
    int n2 = 22;

    cout << "initial values" << endl;
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;

    f1(n1, n2);

    cout << "values after function call" << endl;
    cout << "n1 : " << n1 << endl;
    cout << "n2 : " << n2 << endl;

    return 0;
}

void f1(int v1, int v2){
    v1 = 5555;
    v2 = 6666;

    cout << "values in function call" << endl;
    cout << "v1 : " << v1 << endl;
    cout << "v2 : " << v2 << endl;
}