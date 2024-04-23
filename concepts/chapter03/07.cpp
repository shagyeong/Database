//void형 함수 예제
#include<iostream>
using namespace std;

void icecreamdivision(int number, double totalweight);

int main(void){
    int number;
    double totalweight;

    cout << "enter the number of customers : ";
    cin >> number;

    cout << "enter weight of icecream to divide : ";
    cin >> totalweight;

    icecreamdivision(number, totalweight);

    return 0;
}

void icecreamdivision(int number, double totalweight){
    double portion;

    if(number == 0){
        cout << "cannot divide amog zero customers.\n";
        return;
    }

    portion = totalweight / number;
    cout << "each person receives "
         << portion << " of ice cream." << endl;
}