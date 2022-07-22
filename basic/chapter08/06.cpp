//++ 오버로드
//정수쌍 클래스
#include<iostream>
#include<cstdlib>
using namespace std;

class intpair{
    public:
        //생성자
        intpair(int i1v, int i2v);

        //수정자
        void seti1(int newi1);
        void seti2(int newi2);

        //접근자
        int geti1(void) const;
        int geti2(void) const;

        //오버로드
        intpair operator++(); //프리픽스
        intpair operator++(int); //포스트픽스
    private:
        int i1;
        int i2;
};

int main(void){
    intpair a(0, 0);

    a.seti1(1);
    a.seti2(7);
    cout << "intpair a" << endl;
    cout << a.geti1() << ", " << a.geti2() << endl;
    
    intpair b = ++a;  
    cout << "b : ++a(prefix)" << endl;
    cout << b.geti1() << ", " << b.geti2() << endl;
    
    cout << "changed object a" << endl;
    cout << a.geti1() << ", " << a.geti2() << endl;
    
    cout << endl;

    a.seti1(1);
    a.seti2(7);
    cout << "intpair a" << endl;
    cout << a.geti1() << ", " << a.geti2() << endl;
    
    intpair c = a++;  
    cout << "c : a++(postfix)" << endl;
    cout << c.geti1() << ", " << c.geti2() << endl;
    
    cout << "changed object a" << endl;
    cout << a.geti1() << ", " << a.geti2() << endl;

    return 0;
}

//생성자
intpair::intpair(int i1v, int i2v){
    this->i1 = i1v;
    this->i2 = i2v;
}

//수정자
void intpair::seti1(int newi1){
    i1 = newi1;
}
void intpair::seti2(int newi2){
    i2 = newi2;
}

//접근자
int intpair::geti1(void) const{
    return i1;
}
int intpair::geti2(void) const{
    return i2;
}

//오버로드
intpair intpair::operator++(){ //프리픽스
    this->i1++;
    this->i2++;
    
    cout << "prefix ++ called" << endl;

    return intpair(i1, i2);
}
intpair intpair::operator++(int ignore){ //포스트픽스
    //포스트픽스는 값을 사용 후 증가시키므로
    //temp에 저장해둔 값으로 생성자를 호출
    int temp1 = i1;
    int temp2 = i2;

    i1++;
    i2++;

    cout << "postfix ++ called" << endl;

    return intpair(temp1, temp2);
}