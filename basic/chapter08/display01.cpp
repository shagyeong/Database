//money클래스 '+' 오버로드
#include<iostream>
#include<cmath>
using namespace std;

class money{
    public:
        money();
        money(double amount0);
        money(int dollar0, int cent0);

        double getamount(void) const;
        int getdollar(void) const;
        int getcent(void) const;

        //객체 입출력
        void inmoney(void);
        void outmoney(void) const;
    private:
        int dollar;
        int cent;
};

const money operator+(const money& money1, const money& money2);
const money operator-(const money& money1);

const money operator+(const money& money1, const money& money2){
    //전체 금액을 센트로 나타내는 amount임
    //실수형의 amount와는 다름
    int amount3;
    int amount3abs;
    int dollar3;
    int cent3;
    
    int amount1 = money1.getdollar() * 100 + money1.getcent();
    int amount2 = money2.getdollar() * 100 + money2.getcent();
    
    amount3 = amount1 + amount2;
    amount3abs = abs(amount3);

    dollar3 = amount3abs / 100;
    cent3 = amount3abs & 100;

    if(amount3 < 0){
        dollar3 = -dollar3;
        cent3 = -cent3;
    }

    return money(dollar3, cent3);    
}