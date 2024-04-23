//클래스 예제
#include<iostream>
using namespace std;

class date{
    public:
        int month;
        int day;

        void printdate(void);
};

int main(void){
    date yesterday;
    date birthday;

    //어제 날짜 입력
    cout << "enter yesterday's month : ";
    cin >> yesterday.month;
    cout << "enter yesterday's day : ";
    cin >> yesterday.day;

    //생일 입력
    cout << "enter birthday's month : ";
    cin >> birthday.month;
    cout << "enter birthday's day : ";
    cin >> birthday.day;

    cout << "yesterday : " << endl;
    yesterday.printdate();
    cout << "birthday : " << endl;
    birthday.printdate();

    return 0;
}

void date::printdate(void){
    switch(month){
        case 1:
            cout << "January ";
            break;
        case 2:
            cout << "Feburary ";
            break;
        case 3:
            cout << "March ";
            break;
        case 4:
            cout << "April ";
            break;
        case 5:
            cout << "May ";
            break;
        case 6:
            cout << "June ";
            break;
        case 7:
            cout << "July ";
            break;
        case 8:
            cout << "Augustus ";
            break;
        case 9:
            cout << "September ";
            break;
        case 10:
            cout << " Octobor ";
            break;
        case 11:
            cout << " November ";
            break;
        case 12:
            cout << " December ";
            break;
        default:
            cout << "error in date::printdate";
    }

    cout << day << endl;
}