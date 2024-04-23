//클래스 내부에서 친구로 연산자 오버로드
//키워드는 외부 함수에 대해 프라이빗 데이터에 대한 직접 접근권을 부여
//위를 확인하기 위해 getamount 사용 대신
//멤버 변수 dollar, cent에 직접 접근하는 작업을 오버로드
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

        friend const money operator+(const money& money1, const money& money2);
        friend const money operator-(const money& money1, const money& money2);
        friend bool operator==(const money& money1, const money& money2);
        friend const money operator-(const money& money1);
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
const money operator+(const money& money1, const money& money2){
    int dollar3 = money1.dollar + money2.dollar;
    int cent3 = money1.cent + money2.cent;

    return money(dollar3, cent3);
}
const money operator-(const money& money1, const money& money2){
    int dollar3 = money1.dollar - money2.dollar;
    int cent3 = money1.cent - money2.cent;

    return money(dollar3, cent3);
}
bool operator==(const money& money1, const money& money2){
    return(
        (money1.dollar == money2.dollar) &&
        (money1.cent == money2.cent)
    );
}
const money operator-(const money& money1){
    return money(money1.dollar, money1.cent);
}