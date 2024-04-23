//사용자 정의 함수 예제
#include<iostream>
using namespace std;

double estimateoftotal(int minpeas, int maxpeas, int podcount);
/*
참고-
pea : 콩
pod : 콩깍지
*/

int main(void){
    int mincount;
    int maxcount;
    int podcount;
    double averagepea, yield;

    cout << "enter minimum and maximum number of peas in a pod\n";
    cin >> mincount;
    cin >> maxcount;

    cout << "enter the number of pods : ";
    cin >> podcount;

    cout << "enter the weight of an average pea : ";
    cin >> averagepea;

    yield = averagepea * estimateoftotal(
        mincount,
        maxcount,
        podcount
    );

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout << "min number : " <<  mincount << endl
         << "max number : " <<  maxcount << endl
         << "pod count : " <<  podcount << endl
         << "average pea weight : " <<  averagepea << endl
         << "estimated average yield : " <<  yield << endl;
    
    return 0;

}

double estimateoftotal(int minpeas, int maxpeas, int podcount){
    double averagepea;

    averagepea = (maxpeas + minpeas) / 2.0;
    return podcount * averagepea;
}