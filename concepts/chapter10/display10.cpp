#include<iostream>
using namespace std;

class doublearray{
    public:
        doublearray();
        doublearray(int size0);
        doublearray(const doublearray& daobject); //복사생성자

        void add(double element); //요소 추가
        
        bool full(void) const; //배열이 가득 찼는지 반환
        int getsize(void) const; //배열 크기 반환
        int getnums(void) const; //요소 개수 반환

        void cleanse(void); //배열 비우기

        double& operator[](int index); //[]오버로드
        doublearray& operator=(const doublearray& rightside); //할당연산자 오버로드

        ~doublearray(); //소멸자
    private:
        double* dap; //double array pointer
        int size;
        int num; //요소 개수
};