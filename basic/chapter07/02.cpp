//클래스 에제
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class bankaccount{
    public:
        bankaccount();
        bankaccount(int dollar0, double rate0);
        bankaccount(int dollar0, int cent0, double rate0);
        bankaccount(double balance0, double rate0);

        void update(void);
        void input(void);
        void output(void);

        int getdollar(void);
        int getcent(void);
        double getbalance(void);
        double getrate(void);

        void setbalance(double newbalance);
        void setbalance(int newdollar, int newcent);
        void setrate(double newrate);
    private:
        int dollar;
        int cent;
        double rate;

        int dollarspart(double amount);
        int centspart(double amount);
        int round(double number);

        double fraction(double percent);
};

int main(void){
    bankaccount account1(1345.52, 2.3);
    bankaccount account2;

    cout << "initial account1" << endl;
    account1.output();
    cout << "initial account2" << endl;
    account2.output();

    cout << endl;

    account1 = bankaccount(999, 99, 5.5);
    cout << "account1 reset as" << endl;
    account1.output();

    cout << endl;

    cout << "input account2" << endl;
    account2.input();
    cout << "account2 reset as" << endl;
    account2.output();

    cout << endl;

    account2.update();
    cout << "in one year account2 will grow to" << endl;
    account2.output();

    return 0;
}

bankaccount::bankaccount(){
    dollar = 0;
    cent = 0;
    
    rate = 0.0;
}
bankaccount::bankaccount(int dollar0, double rate0){
    dollar = dollar0;
    cent = 0;
    
    setrate(rate);
}
bankaccount::bankaccount(int dollar0, int cent0, double rate0){
    setbalance(dollar0, cent0);
    
    setrate(rate);
}
bankaccount::bankaccount(double balance0, double rate0){
    dollar = dollarspart(balance0);
    cent = centspart(balance0);
    
    setrate(rate);
}

void bankaccount::update(void){
    double balance = dollar + cent * 0.01;
    balance += fraction(rate) * balance;
    
    dollar = dollarspart(balance);
    cent = centspart(balance);
}
void bankaccount::input(void){
    double doublebalance;
    cout <<"enter account balance : ";
    cin >> doublebalance;

    dollar = dollarspart(doublebalance);
    cent = centspart(doublebalance);
    
    cout << "enter interest rate : ";
    cin >> rate;

    setrate(rate);
}
void bankaccount::output(void){
    cout << "dollar : " << dollar << endl;
    cout << "cent : " << cent << endl;
    cout << "rate : " << rate << endl;
}

int bankaccount::getdollar(void){
    return dollar;
}
int bankaccount::getcent(void){
    return cent;
}
double bankaccount::getbalance(void){
    return dollar + cent * 0.01;
}
double bankaccount::getrate(void){
    return rate;
}

void bankaccount::setbalance(double newbalance){
    dollar = dollarspart(newbalance);
    cent = centspart(newbalance);
}
void bankaccount::setbalance(int newdollar, int newcent){
    //두 단위의 부호가 다른 경우를 무효하다고 봄
    if((newdollar < 0 && newcent > 0) ||
       (newdollar > 0 && newcent < 0)){
        cout << "inconsistent account data" << endl;
        exit(1);
    }

    dollar = newdollar;
    cent = newcent;
}
void bankaccount::setrate(double newrate){
    if(newrate >= 0.0){
        rate = newrate;
    }
    else{
        cout << "cannot have a negative interest rate" << endl;
        exit(1);
    }
}

//프라이빗 멤버 함수
int bankaccount::dollarspart(double amount){
    return static_cast<int>(amount);
}
int bankaccount::centspart(double amount){
    int intcent = round(fabs(amount * 100)) % 100;
    if(amount < 0){
        return -intcent;
    }
    else{
        return intcent;
    }
}
int bankaccount::round(double number){
    return static_cast<int>(floor(number + 0.5));
}

double bankaccount::fraction(double percent){
    return percent / 100.0;
}