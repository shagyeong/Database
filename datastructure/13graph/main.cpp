#include<iostream>
using namespace std;

#include "vertex.h"
#include "branch.h"
#include "graph.h"

int main(void){
    vertex j01("j01");
    vertex j02("j02");
    vertex j03("j03");
    vertex j04("j04");
    vertex j05("j05");
    vertex j06("j06");
    vertex j07("j07");
    vertex j08("j08");
    vertex j09("j09");
    vertex j10("j10");
    vertex j11("j11");
    vertex j12("j12");

    vertex adj01[] = {j02, j03};
    vertex adj02[] = {j04, j05};
    vertex adj03[] = {j06};
    vertex adj04[] = {j07};
    vertex adj05[] = {j08};
    vertex adj06[] = {j09};
    vertex adj07[] = {j10};
    vertex adj08[] = {j10};
    vertex adj09[] = {j11};
    vertex adj10[] = {j11};
    vertex adj11[] = {j12};

    graph gr_j01("j01", adj01);
    graph gr_j02("j02", adj02);
    graph gr_j03("j03", adj03);
    graph gr_j04("j04", adj04);
    graph gr_j05("j05", adj05);
    graph gr_j06("j06", adj06);
    graph gr_j07("j07", adj07);
    graph gr_j08("j08", adj08);
    graph gr_j09("j09", adj09);
    graph gr_j10("j10", adj10);
    graph gr_j11("j11", adj11);

    //2선 정차시 경로
    vertex transit01[] = {j01, j02, j04, j07, j10, j11, j12};

    return 0;
}