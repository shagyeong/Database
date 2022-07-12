//난수 함수 호출, 난수 범위 지정 예제
#include<iostream>
#include<cstdlib>
using namespace std;

int main(void){
    int month;
    int day;

    cout << "enter 2 integers as month and day\n";
    cin >> month;
    cin >> day;

    srand(month * day);

    int prediction;
    char answer;

    cout << "weather for today\n";

    do{
        prediction = rand() % 3;
        switch(prediction){
            case 0:
                cout << "today's gonna be sunny\n";
                break;
            case 1:
                cout << "today's gonna be cloudy\n";
                break;
            case 2:
                cout << "today's gonna be stormy\n";
                break;
            default:
                cout << "weather program is not functioning properly\n";
        }
        cout << "do you want weather for the next day?(y/n) : ";
        cin >> answer;
    }while(answer == 'y' || answer == 'Y');

    //cout << "That's it from your 24 hour weather program.\n";
    return 0;
}