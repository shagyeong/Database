//파일 입출력 예제
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){
    string text;
    fstream inputstream;

    inputstream.open(argv[1]);

    while(inputstream >> text){
        cout << text << endl;
    }

    inputstream.close();

    exit(1);
}