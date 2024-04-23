//동적 인스턴스 실습
#include<iostream>
using namespace std;

class date{
    public:
        date();
        date(int month0, int day0);

        void setdate(int newmonth, int newday); //세터
        void indate(void); //입력
        void outdate(void); //출력
    private:
        int month;
        int day;
};

int main(void){
    date* date01;
    date* date02;
    //date* date03;
    //date* date04;

    date01 = new date(9, 21);

    date02 = new date;
    
    date02->setdate(7, 22);
    date02->outdate();
    
    (*date02).setdate(6, 23);
    date02->outdate();

    return 0;
}

date::date(){
    this->month = 1;
    this->day = 1;
}
date::date(int month0, int day0){
    this->month = month0;
    this->day = day0;
}

void date::setdate(int newmonth, int newday){
    this->month = newmonth;
    this->day = newday;
}
void date::indate(void){
    cout << "enter month : ";
    cin >> this->month;
    cout << "enter day : ";
    cin >> this->day;
}
void date::outdate(void){
    cout << this->month << " ";
    cout << this->day << endl;
}