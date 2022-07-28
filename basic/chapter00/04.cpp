//상속 클래스의 생성자
#include<iostream>
using namespace std;

class a{
    public:
        a();
        a(int i1v);

        int geti1(void);
    private:
        int i1;
};
a::a(){
    i1 = 0;
}
a::a(int i1v){
    i1 = i1v;
}
int a::geti1(void){
    return i1;
}

class b : public a{
    public:
        b();
        b(int i1v, int i2v);

        int geti2(void);
    private:
        int i2;
};
b::b(){
    a();
    int i2 = 0;
}
b::b(int i1v, int i2v):a(i1v){
    i2 = i2v;
}
int b::geti2(void){
    return i2;
}

int main(void){
    b b1(21, 17);

    cout << b1.geti1() << endl;
    cout << b1.geti2() << endl;

    return 0;
}