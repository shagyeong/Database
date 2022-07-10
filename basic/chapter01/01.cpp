//개행문자와 기본 입출력
#include<iostream>
using namespace std;

int main(void){
    int nol; //nuber of language : 사용자가 익힌 프로그래밍 언어 수

    cout << "hello reader.\n"
         << "welcome to C++.\n";

    cout << "how many p. language have you used? ";
    cin >> nol;

    if(nol < 1){
        cout << "Read the preface. You may prefer\n"
             << "a more elementary book by the same author.\n";
    }
    else{
        cout << "Enjoy the book.\n";
    }

    return 0;
}