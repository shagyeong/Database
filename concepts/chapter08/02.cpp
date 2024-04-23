//클래스 내부에서 연산자 오버로드
#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

//damount : double amount : 실수형 총액
//iamount : integer amount : damount * 100의 정수형 센트 총액
class money{
    public:
        money();
        money(double damount);
        money(int dollar0);
        money(int dollar0, int cent0);

        double getamount(void) const;
        int getdollar(void) const;
        int getcent(void) const;

        void inmoney(void);
        void outmoney(void) const;

        const money operator+(const money& money2) const;
        const money operator-(const money& money2) const;
        bool operator==(const money& money2) const;
        const money operator-() const; //부정연산자
    private:
        int dollar;
        int cent;

        int dollarpart(double damount) const;
        int centpart(double damount) const;
        int round(double number) const;
};

int main(void){
    money yourAmount;
    money myAmount(10, 9);
    cout << "Enter an amount of money: ";
    yourAmount.inmoney( );

    cout << "Your amount is "; 
    yourAmount.outmoney( ); 
    cout << endl;
    cout << "My amount is "; 
    myAmount.outmoney( ); 
    cout << endl;

    if (yourAmount == myAmount)
        cout << "We have the same amounts.\n";
    else
        cout << "One of us is richer.\n";

    money ourAmount = yourAmount + myAmount;
    yourAmount.outmoney( ); cout << " + "; myAmount.outmoney( ); 
    cout << " equals "; ourAmount.outmoney( ); cout << endl;

    money diffAmount = yourAmount - myAmount;
    yourAmount.outmoney( ); cout << " - "; myAmount.outmoney( ); 
    cout << " equals "; diffAmount.outmoney( ); cout << endl;

    return 0;
}

//public:
money::money(){
    this->dollar = 0;
    this->cent = 0;
}
money::money(double damount){
    this->dollar = dollarpart(damount);
    this->cent = centpart(damount);
}
money::money(int dollar0){
    this->dollar = dollar0;
    this->cent = 0;
}
money::money(int dollar0, int cent0){
    this->dollar = dollar0;
    this->cent = cent0;
}

double money::getamount(void) const{
    int iamount;
    double damount;
    iamount = (
        this->dollar * 100 +
        this->cent
    );

    damount = static_cast<double>(iamount);
    damount /= 100;

    return damount;
}
int money::getdollar(void) const{
    return this->dollar;
}
int money::getcent(void) const{
    return this->cent;
}

void money::inmoney(void){
    cout << "enter dollars : ";
    cin >> this->dollar;
    cout << "enter cents : ";
    cin >> this->cent;
}
void money::outmoney(void) const{
    double damount = this->getamount();
    cout << damount << "$" << endl;
}

//private:
int money::dollarpart(double damount) const{
    int iamount;
    iamount = static_cast<int>(damount * 100);
    
    return iamount / 100;
}
int money::centpart(double damount) const{
    int iamount;
    iamount = static_cast<int>(damount * 100);

    return iamount % 100;
}
//int money::round(double number) const{
//
//}

//연산자 오버로드
const money money::operator+(const money& money2) const{
    double damount3;
    damount3 = this->getamount() + money2.getamount();
    
    return money(damount3);
}
const money money::operator-(const money& money2) const{
    double damount3;
    damount3 = this->getamount() - money2.getamount();
    
    return money(damount3);
}
bool money::operator==(const money& money2) const{
    return (
        (this->getdollar() == money2.getdollar())&&
        (this->getcent() == money2.getcent())
    );
}
const money money::operator-() const{
    return money(
        -this->dollar,
        -this->cent
    );
}