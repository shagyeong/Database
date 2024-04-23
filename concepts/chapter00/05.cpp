//rapid transit의 is a, has a 이론
//추상 클래스의 인스턴스를 사용할 수 없습니다.
#include<iostream>
#include<string>
using namespace std;

class person{
    public:
        person();
        person(string namev, int agev);

        virtual void eat() = 0;

        void setname(string namev);
        void setage(int agev);

        string getname(void);
        int getage(void);
    private:
        string name;
        int age;
};

class student : public person{
    public:
        student(string namev, int agev):person(namev, agev){}

        virtual void eat(void);
        void study(void);
    private:
};

class professor : public person{
    public:
        professor(string namev, int agev):person(namev, agev){}

        virtual void eat(void);
        void lecture(void);
    private:
};

class group{
    public:
        person(person* p1v, person* p2v, person* p3v);

    private:
        person* p1;
        person* p2;
        person* p3;
};