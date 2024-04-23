//생성자 예제
#include<iostream>
#include<cstdlib>
using namespace std;

class date{
    public:
        date();
        date(int month0);
        date(int month0, int day0);

        void input(void);
        void output(void);

        int getmonth(void);
        int getday(void);
    private:
        int month;
        int day;

        void testdate(void);
};

int main(void){
    date date1;
    date date2(2);
    date date3(9, 21);

    cout << "initial dates" << endl;

    date1.output();
    date2.output();
    date3.output();

    date1 = date(10, 31);
    cout << "date 1 reset as" << endl;
    date1.output();

    return 0;
}

date::date(){
    month = 1;
    day = 1;
}
date::date(int month0){
    month = month0;
    day = 1;
    
    testdate();
}
date::date(int month0, int day0){
    month = month0;
    day = day0;

    testdate();
}

void date::input(void){
    cout << "enter month : ";
    cin >> month;
    cout << "enter day : ";
    cin >> day;
}
void date::output(void){
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
int date::getmonth(void){
    return month;
}
int date::getday(void){
    return day;
}

void date::testdate(void){
    if((month < 1) || (month > 12)){
        cout << "illegal month value" << endl;
        exit(1);
    }
    if((day < 1) || (day > 31)){
        cout << "illegal day value" << endl;
        exit(1);
    }
}