//리터럴 상수와 입출력 사용

#include<iostream>
using namespace std;

int main(void){
    const double PI = 3.14;
    double radius;
    double area;

    cout << "enter the radius : ";
    cin >> radius;

    area = radius * radius * PI;

    cout << "the area of the circle is " << area << endl;

    return 0;

}