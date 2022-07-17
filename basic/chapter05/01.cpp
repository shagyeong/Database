//배열 예제
//최대값 찾기
#include<iostream>
using namespace std;

int main(void){
    int i;
    int score[5];
    int max;

    cout << "enter 5 scores\n";
    cin >> score[0];
    max = score[0];

    for(i = 1; i < 5; i++){
        cin >> score[i];
        if(score[i] > max){
            max = score[i];
        }
    }

    cout << "highest score : " << max << endl;

    return 0;
}
