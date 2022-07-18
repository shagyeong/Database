//구조체 예제
//구조체를 멤버로 갖는 구조체
#include<iostream>
using namespace std;

struct date{
    int month;
    int day;
};

struct account{
    double balance;
    double interestrate;

    date birthday;
};

void getdate(date& date0);
void getaccount(account& account0);

int main(void){
    account account0001;

    getaccount(account0001);

    cout << "balance : " << account0001.balance << endl
         << "interestrate : " << account0001.interestrate << endl
         << "birthday : " << account0001.birthday.month << " "
                          << account0001.birthday.day << endl;
    
    return 0;
}

void getdate(date& date0){
    cout << "enter month : ";
    cin >> date0.month;
    cout << "enter day : ";
    cin >> date0.day;
}

void getaccount(account& account0){
    cout << "enter balance : ";
    cin >> account0.balance;
    cout << "enter interestrate : ";
    cin >> account0.interestrate;

    cout << "enter birthday" << endl;
    getdate(account0.birthday);
}