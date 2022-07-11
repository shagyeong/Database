#include<iostream>
using namespace std;

int main(void){
    int countdown;

    cout << "how many greetings do you want?";
    cin >> countdown;

    while(countdown > 0){
        cout << "hello" << endl;
        countdown -= 1;
    }

    return 0;
}