//사용자 정의 함수 예제
#include<iostream>
using namespace std;

double totalcost(int number, double price);

int main(void){
    double price, bill;
    int number;

    cout << "enter the number of items purchased : ";
    cin >> number;

    cout << "enter the price per item : ";
    cin >> price;

    bill = totalcost(number, price);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "number: " << number << endl
         << "price: " << price << endl
         << "bill: " << bill << endl;
}

double totalcost(int number, double price){
    const double TAXRATE = 0.05;
    double subtotal;

    subtotal = price * number;
    subtotal *= (1 + TAXRATE); //관세 적용

    return subtotal;
}