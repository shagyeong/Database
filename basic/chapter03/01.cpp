//cmath 함수 호출
//소수점 형식 지정
#include<iostream>
#include<cmath>
using namespace std;

int main(void){
    const double COST_PER_SQ_FT = 10.50;

    double budget;
    double area;
    double lengthside;

    cout << "enter the amount butgeted for your dog house $ : ";
    cin >> budget;

    area = budget / COST_PER_SQ_FT;
    lengthside = sqrt(area);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "buget : " << budget << endl;
    cout << "lengthside : " << lengthside << endl;

    return 0;
}