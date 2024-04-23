//참조 호출 예제
//입력 함수에 참조 호출이 사용되는 것을 반복적으로 확인
#include<iostream>
using namespace std;

double unitprice(int dia, double price);

void getdata(
    int& sdia, //small 피자의 직경
    int& ldia, //large 피자의 직경
    double& sprice, //small 피자의 가격
    double& lprice //large 피자의 가격
);
void getresults(
    int sdia, //small 피자의 직경
    int ldia, //large 피자의 직경
    double sprice, //small 피자의 가격
    double lprice //large 피자의 가격
);

int main(void){
    int sdia;
    int ldia;
    double sprice;
    double lprice;

    getdata(sdia, ldia, sprice, lprice);
    getresults(sdia, ldia, sprice, lprice);

    return 0;
}

double unitprice(int dia, double price){
    const double PI = 3.141592;
    double radius;
    double area;

    radius = dia / static_cast<double>(2);
    area = PI * radius * radius;

    return price / area;
}

void getdata(
    int& sdia,
    int& ldia,
    double& sprice,
    double& lprice
){
    cout << "enter diameter of the s.pizza : ";
    cin >> sdia;
    cout << "enter diameter of the l.pizza : ";
    cin >> ldia;
    cout << "enter price of the s.pizza : ";
    cin >> sprice;
    cout << "enter price of the l.pizza : ";
    cin >> lprice;
}

void getresults(
    int sdia,
    int ldia,
    double sprice,
    double lprice
){
    double ups = unitprice(sdia, sprice);
    double upl = unitprice(ldia, lprice);

    cout << "s.pizza" << endl
         << "diameter : " << sdia << endl
         << "price : " << sprice << endl
         << "unit price : " << ups << endl;

    cout << "l.pizza" << endl
         << "diameter : " << sdia << endl
         << "price : " << lprice << endl
         << "unit price : " << upl << endl;

    if(ups > upl){
        cout << "large one is better to buy" << endl;
    }
    else if(upl > ups){
        cout << "small one is better to buy" << endl;
    }
    else{
        cout << "whatever";
    }
}
