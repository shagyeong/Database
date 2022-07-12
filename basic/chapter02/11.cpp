//파일 입출력 예제
//bash 11.sh
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){
    string firstname;
    string middlename;
    string lastname;
    int score;
    fstream inputstream;

    inputstream.open(argv[1]);
    
    inputstream >> score;
    
    inputstream >> firstname;
    inputstream >> middlename;
    inputstream >> lastname;

    cout << "score : " << score << endl;
    cout << "name : "
         << firstname << " "
         << middlename << " "
         << lastname << endl;
        
    inputstream.close();

    exit(1);
}