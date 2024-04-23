//[] 오버로드
//문자쌍 클래스
#include<iostream>
#include<cstdlib>
using namespace std;

class charpair{
    public:
        charpair(); //본문을 의도적으로 비워둠([] 오버로드 사용을 위함)
        charpair(char c1v, char c2v);

        char& operator[](int index);
    private:
        char c1;
        char c2;
};

int main(void){
    charpair cp1;
    cp1[1] = 'A';
    cp1[2] = 'B';

    cout << "cp1[1] : " << cp1[1] << endl;
    cout << "cp1[2] : " << cp1[2] << endl;

    cout << "enter 2 letters : ";
    cin >> cp1[1] >> cp1[2];

    cout << "entered letters : " << endl;

    cout << "cp1[1] : " << cp1[1] << endl;
    cout << "cp1[2] : " << cp1[2] << endl;

    return 0;
}

charpair::charpair(){

}
charpair::charpair(char c1v, char c2v){
    c1 = c1v;
    c2 = c2v;
}

char& charpair::operator[](int index){
    if(index == 1){
        return c1;
    }
    else if(index == 2){
        return c2;
    }
    else{
        cout << "illegal index" << endl;
        exit(1);
    }
}