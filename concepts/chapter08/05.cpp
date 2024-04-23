//친구로 연산자 오버로드
//<<, >>연산자 오버로드
//cout << money1 - money; : 뺄셈 오버로드와 << 오버로드로 익명 객체 출력 확인
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

        friend istream& operator>>(istream& istream0, money& money0);
        friend ostream& operator<<(ostream& ostream0, const money& money0);
    private:
        int dollar;
        int cent;

        int dollarpart(double damount) const;
        int centpart(double damount) const;
        int round(double number) const;
};

int main(void){
    money money1(20, 50);
    money money2(10.25);

    cout << "amount of money1 is " << money1 << endl;
    cout << "amount of money2 is " << money2 << endl;

    cout << money1 << " - " << money2 << " = " << money1 - money2 << endl;

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

istream& operator>>(istream& istream0, money& money0){
    //"$0.00"의 형태로 입력을 받음
    char dollarsign;
    double damount0;
    int iamount0;

    istream0 >> dollarsign;
    istream0 >> damount0;

    //money0.dollar = money::dollarpart(damount0)
    //money0.cent = money::centpart(damount0)
    //damount -> dollar, cent 변환 함수 dollarspart(), centpart()를 여기서 사용
    //구현을 해두지 않아 다르게 구현함

    iamount0 = static_cast<int>(damount0 * 100);
    money0.dollar = iamount0 / 100;
    money0.cent = iamount0 % 100;

    return istream0;
}
ostream& operator<<(ostream& ostream0, const money& money0){
    ostream0 << money0.getamount() << "$";
    return ostream0;
}