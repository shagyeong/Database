//오버로딩 예제
#include<iostream>
using namespace std;

double avg(double n1, double n2);
double avg(double n1, double n2, double n3);

int main(void){
    cout << "the average of 1, 2 is : " << avg(1, 2) << endl;
    cout << "the average of 1, 2, 3 is : " << avg(1, 2, 3) << endl;

    return 0;
}

double avg(double n1, double n2){
    return (n1 + n2 ) / 2.0;
}
double avg(double n1, double n2, double n3){
    return (n1 + n2 + n3) / 3.0;
}
