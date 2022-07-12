//do-while 예제
#include<iostream>
using namespace std;

int main(void){
    int countdown;

    cout << "how many greetings do you want? : ";
    cin >> countdown;

    do{
        cout << "hello" << endl;
        countdown -= 1;
    }while(countdown > 0);

    return 0;
}