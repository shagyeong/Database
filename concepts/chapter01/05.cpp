//입출력과 스트링

#include<iostream>
#include<string>
using namespace std;

int main(void){
    string dogname;
    int dogage;
    int humanage;

    const int AGERATE = 7;

    cout << "enter age of the dog : ";
    cin >> dogage;
    humanage = dogage * AGERATE;

    cout << "enter name of the dog : ";
    cin >> dogname;

    cout << dogname 
         << "'s age is approximately equivalent to a "
         << humanage 
         << " year old human."
         << endl;

    return 0;
}