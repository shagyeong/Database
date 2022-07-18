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

        void testdate();
};