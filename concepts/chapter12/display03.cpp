//파일 열기 실패
#include<iostream>
#include<fstream>
#include<cstdlib>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

int main(void){
    ifstream istream;
    ofstream ostream;

    istream.open("xxxxxxxx.txt"); //존재하지 않는 파일
    if(istream.fail() == true){
        cout << "input file opening failed" << endl;
        exit(1);
    }

    //이하생략(display01과 같음)

    return 0;
}