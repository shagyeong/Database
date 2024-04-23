//다른 형식의 파일을 cpp로 컴파일
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int main(int argc, char* argv[]){
    ifstream i;
    ofstream o;

    i.open(argv[1]);
    o.open(argv[2], ios::app);

    int iter;

    o << "cout << \"";
    i >> iter; o << iter; o << " ";
    i >> iter; o << iter;
    o << "\" << endl;}";
    
    i.close();
    o.close();

    exit(0);
}