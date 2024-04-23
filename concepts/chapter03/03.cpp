//main()의 리턴 예제
#include<iostream>
#include<cstdlib>
using namespace std;

int main(void){
    cout << "hello there" << endl;
    exit(1);

    cout << "this statement will never be executed!" << endl;

    return 0;
}