#include<iostream>
#include "./vertex.h"
#include "./linkedlist.h"
using namespace std;

int main(void){
    linkedlist l1;

    l1.append(21);
    l1.append(22);
    l1.append(23);
    l1.append(24);

    l1.iterate();

    cout << l1.pop() << " deleted" << endl;

    l1.iterate();

    cout << l1.pop() << " deleted" << endl;

    l1.iterate();

    return 0;
}


