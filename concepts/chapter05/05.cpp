//배열 예제
//각 점수와 평균의 차를 출력
#include<iostream>
using namespace std;
const int NOS = 10; //the number of scores : 점수 개수(배열 크기)

void fillscore(int scores[], int size, int& numberused);
double average(const int scores[], int numberused);
void difference(const int scores[], int numberused);

int main(void){
    int scores[NOS];
    int numberused;

    cout << "enter scores\n";
    fillscore(scores, NOS, numberused);
    difference(scores, numberused);

    return 0;
}

void fillscore(int scores[], int size, int& numberused){
    //사이즈 이하의 개수를 입력하라
    //음수를 입력해 입력 중지
    int next = 0;
    int index = 0;

    cin >> next;

    while((next >= 0) && (index < size)){
        scores[index] = next;
        index++;
        cin >> next;
    }

    numberused = index; //사용자가 입력한 원소 개수
}

double average(const int scores[], int numberused){
    double total = 0;
    
    for(int index = 0; index < numberused; index++){
        total += scores[index];
    }

    if(numberused > 0){
        return total / numberused;
    }
    else{
        //에러 : 0으로 나눌 수 없습니다.
        return 0;
    }
}

void difference(const int scores[], int numberused){
    double avg = average(scores, numberused);

    for(int index = 0; index < numberused; index++){
        cout << scores[index] << " "
             << scores[index] - avg
             << endl;
    }
}