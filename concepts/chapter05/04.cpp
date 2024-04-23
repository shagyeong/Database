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
    for(int plantnumber = 1;
        plantnumber <= lastplantnumber;
        plantnumber++){
        cout << endl
             << "enter production data for plant number "
             << plantnumber
             << endl;

        gettotal(arr[plantnumber - 1]);
            
    }
}

void scale(int arr[], int size){
    for(int index = 0; index < size; index++){
        arr[index] = round(arr[index] / 1000.0);
    }

}
void graph(const int astreriskcount[], int lastplantnumber){
    cout << "\nunits produced in thousands of units : \n";

    for(int plantnumber = 1;
        plantnumber <= lastplantnumber;
        plantnumber++){
        cout << "plant #" << plantnumber << " ";
        printasterisks(astreriskcount[plantnumber - 1]);
        cout << endl;
    }
}
void gettotal(int& sum){
    cout << "enter number of units produced by each department.\n"
         << "append a negative number to the end of the list.\n";

    sum = 0;
    int next;

    cin >> next;

    while(next >= 0){
        sum = sum + next;
        cin >> next;
    }   

    cout << "total : " << sum << endl;

}
int round2(double number){
    return static_cast<int>(floor(number + 00.5));
}
void printasterisks(int n){
    for(int count = 0; count < n; count++){
        cout << "*";
    }
}
