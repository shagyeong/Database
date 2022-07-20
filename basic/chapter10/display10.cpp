//연산자 오버로드 선정리 후 정리
#include<iostream>
using namespace std;

class doublearray{
    public:
        doublearray();
        doublearray(int size);
        doublearray(const doublearray& daobject); //복사생성자

        void add(double element); //요소 추가
        
        bool full(void) const; //배열이 가득 찼는지 반환
        int getsize(void); //배열 크기 반환
        int getnums(void); //요소 개수 반환

        void cleanse(void); //배열 비우기


    private:
};