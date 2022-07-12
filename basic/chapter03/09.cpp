//사용자 정의 함수 예제
#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.141592;

double area(double radius);
double volume(double radius);

int main(void){
    double radius;
    double circle; //원의 면적
    double sphere; //구의 부피

    cout << "enter a radius : ";
    cin >> radius;

    circle = area(radius);
    sphere = volume(radius);

    cout << "circle : " << circle << endl;
    cout << "sphere : " << sphere << endl;
    
    return 0;
}

double area(double radius){
    return PI * pow(radius, 2);
}
double volume(double radius){
    return (4.0 / 3.0) * PI * pow(radius, 3);
}
