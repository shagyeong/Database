#include<iostream>
#include<cmath>
using namespace std;

const int PLANTS = 4; //plant 개수

void inputdata(int arr[], int lastplantnumber);
void scale(int arr[], int size);
void graph(const int astreriskcount[], int lastplantnumber);
void gettotal(int& sum);
int round2(double number);
void printasterisks(int n);

int main(void){
    int production[PLANTS];

    cout << "this program displays a graph" << endl
         << "showing production for each plant in the company" << endl;
    
    inputdata(production, PLANTS);
    scale(production, PLANTS);
    graph(production, PLANTS);

    return 0;
}

void inputdata(int arr[], int lastplantnumber){
    
}
void scale(int arr[], int size){

}
void graph(const int astreriskcount[], int lastplantnumber){

}
void gettotal(int& sum){

}
int round2(double number){

}
void printasterisks(int n){

}
