//배열 검색 예제
#include<iostream>
using namespace std;

const int SIZE = 20;

void fillarray(int array[], int& numberused);
int search(const int array[], int numberused, int target);

int main(void){
    int array[SIZE];
    int numberused;
    int target;

    fillarray(array, numberused);

    char answer;
    int result;

    do{
        cout << "enter a number to search for : ";
        cin >> target;

        result = search(array, SIZE, target);
        
        if(result == -1){
            cout << target << " is not on list.\n";
        }
        else{
            cout << "target : " << target << endl
                 << "index : " << result << endl;
        }

        cout << "search again?(y/n) : ";
        cin >> answer;
    }while((answer != 'n') && (answer != 'N'));

    cout << "program ends\n";

    return 0;
}

void fillarray(int array[], int& numberused){
    int next = 0;
    int index = 0;

    cout << "enter up to " << SIZE << " numbers\n"
         << "negative number == end of input\n";
    cin >> next;

    while((next >= 0) && (index < SIZE)){
        array[index] = next;
        cin >> next;

        index++;
    }

    numberused = index;
}
int search(const int array[], int numberused, int target){
    int index = 0;
    bool found = false;

    while((!found)&&(index < numberused)){
        if(target == array[index]){
            found = true;    
        }
        else{
            index++;
        }
    }

    if(found){ //found == true와 동치
        return index;
    }
    else{
        return -1;
    }
}