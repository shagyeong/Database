//클래스 예제
//퍼블릭 멤버와 프라이빗 멤버 구분
#include<iostream>
#include<cstdlib>
using namespace std;

class date{
    public:
        //객체 입출력
        void input(void);
        void output(void);

        //객체 멤버 변수 수정(mutator)
        void set(int newmonth, int newday);
        void set(int newmonth); //오버로드 : 각 달의 첫째 날로 설정

        //객체 멤버 변수 접근자
        int getmonth(void);
        int getday(void);        
    private:
        int month;
        int day;
};

int main(void){
    date today;
    date birthday;

    //객체 입력
    cout << "enter today's date" << endl;
    today.input();
    cout << "enter birthday's date" << endl;
    birthday.input();

    //객체 출력
    cout << "today : " << endl;
    today.output();
    cout << "birthday : " << endl;
    birthday.output();

    //객체 조작
    birthday.set(9, 21);
    cout << "brithday jsut has been set as" << endl;
    birthday.output();

    return 0;
}

//객체 입출력
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
//객체 멤버 변수 수정(mutator)
void date::set(int newmonth, int newday){
    month = newmonth;
    day = newday;
}
void date::set(int newmonth){
    month = newmonth;
    day = 1;
}
//객체 멤버 변수 접근자
int date::getmonth(void){
    return month;
}
int date::getday(void){
    return day;
}