#include<iostream>
using namespace std;

#include "vertex.h"
#include "linkedlist.h"

int main(void){
    linkedlist ll1;

    ll1.append(11);
    ll1.append(12);
    ll1.append(13);
    ll1.append(14);
    ll1.append(15);
    
    ll1.append(11);
    ll1.append(11);
    ll1.append(11);
    ll1.append(11);
    
    cout << ll1.count(11) << endl;

    return 0;
}