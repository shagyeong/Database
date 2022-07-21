//대부분의 예제는 클래스 money의 변형
//기본형을 선언해둠
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
    private:
        int dollar;
        int cent;

        int dollarpart(double damount) const;
        int centpart(double damount) const;
        int round(double number) const;
};

int main(void){
    money m1;
    money m2(10.21);
    money m3(22);
    money m4(11, 23);

    m1.inmoney();

    m1.outmoney();
    m2.outmoney();
    m3.outmoney();
    m4.outmoney();

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