//데이터 손실과 자동 형 변환 예제
#include<iostream>
using namespace std;

const double RATE = 150.00; //단위급여

double fee(int hoursworked, int minutesworked);

int main(void){
    int hours, minutes;
    double bill;

    cout << "enter the hours and minutes of your consultation\n";
    cin >> hours;
    cin >> minutes;

    bill = fee(hours, minutes);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "hoursworked : " <<  hours << endl
         << "minutesworked : " <<  minutes << endl
         << "bill : " <<  bill << endl;

    return 0;
}

double fee(int hoursworked, int minutesworked){
    int quarterhours;

    minutesworked = hoursworked * 60 + minutesworked;
    quarterhours = minutesworked / 15;

    cout << "minutesworked : " << minutesworked << endl;
    cout << "hoursworked : " << hoursworked << endl;
    cout << "quarterhours : " << quarterhours << endl << endl;

    return quarterhours * RATE;
}