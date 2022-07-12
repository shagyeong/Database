//두 번째 피자 예제-다른 피자 모양에 대해 오버로딩
//편의를 위해 원(직경), 마름모 -> 원(반지름), 직사각형으로 풀이
#include<iostream>
using namespace std;

void getdata(double& radius, double& price); //원형 피자
void getdata(double& width, double& height, double& price); //직사각형 피자

double unitprice(double radius, double price); //원형 피자
double unitprice(double width, double height, double price); //직사각형 피자

int main(void){
    //원형
    double radius;
    double cprice;
    double cup;

    //직사각형
    double width;
    double height;
    double rprice;
    double rup;

    getdata(radius, cprice);
    getdata(width, height, rprice);

    cup = unitprice(radius, cprice);
    rup = unitprice(width, height, rprice);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "circular pizza" << endl
         << "radius : " <<  radius << endl
         << "price : " <<  cprice << endl
         << "unitprice : " <<  cup << endl;
    cout << "rectangular pizza" << endl
         << "width : " <<  width << endl
         << "height : " <<  height << endl
         << "price : " <<  rprice << endl
         << "unitprice : " <<  rup << endl;

    if(cup < rup){
        cout << "c.pizza is better to buy" << endl;
    }
    else if(rup < cup){
        cout << "r.pizza is better to buy" << endl;
    }
    else{
        cout << "whatever" << endl;
    }
    
    return 0;
}

void getdata(double& radius, double& price){
    cout << "c.getdata called" << endl;
    
    cout << "enter the radius of r.pizza : ";
    cin >> radius;
    cout << "enter the price of r.pizza : ";
    cin >> price;
}
void getdata(double& width, double& height, double& price){
    cout << "r.getdata called" << endl;

    cout << "enter the width of r.pizza : ";
    cin >> width;
    cout << "enter the height of r.pizza : ";
    cin >> height;
    cout << "enter the price of r.pizza : ";
    cin >> price;
}

double unitprice(double radius, double price){
    cout << "c.unitprice called" << endl;

    const double PI = 3.141592;
    return price / (radius * radius * PI);
}
double unitprice(double width, double height, double price){
    cout << "r.unitprice called" << endl;

    return price / (width * height);
}
