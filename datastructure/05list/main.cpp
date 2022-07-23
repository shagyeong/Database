#include<iostream>
using namespace std;

#include "vertex.h"
#include "linkedlist.h"

int main(void){
    linkedlist ll1;

    ll1.append(16);
    ll1.append(18);
    //ll1.append(19);
    //ll1.append(20);

    ll1.sneaky();

    return 0;
}