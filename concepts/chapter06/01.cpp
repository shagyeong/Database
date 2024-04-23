//구조체 예제
#include<iostream>
using namespace std;

struct cdaccount{
    double balance;
    double interestrate;
    int term;
};

//getter이므로 참조 전달
void getdata(cdaccount& cdaccount0);
void setdata(cdaccount& cdaccount0);

int main(void){
    cdaccount account0001;

    getdata(account0001);
    setdata(account0001);

    cout << "balance : " << account0001.balance << endl
         << "interestrate : " << account0001.interestrate << endl
         << "term : " << account0001.term << endl;

    return 0;
}

void getdata(cdaccount& cadaccount0){
    cout << "enter balance : ";
    cin >> cadaccount0.balance;
    cout << "enter interestrate : ";
    cin >> cadaccount0.interestrate;
    cout << "enter term : ";
    cin >> cadaccount0.term;
}

void setdata(cdaccount& cdaccount0){
    double ratefraction;
    double interest;

    ratefraction = cdaccount0.interestrate / 100.0;
    interest = cdaccount0.balance * (ratefraction * (cdaccount0.term / 12.0));
    cdaccount0.balance = cdaccount0.balance + interest;
}