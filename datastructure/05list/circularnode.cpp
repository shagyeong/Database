//#include<iostream>
//using namespace std;
//
//class cnode{
//    public:
//    //생성자
//        cnode();
//        cnode(cnode* leftvalue, cnode* rightvalue, int itemvalue);
//    //멤버 변수
//        cnode* left;
//        cnode* right;
//        int item;
//    //멤버 메서드
//        void setleft(cnode* leftvalue);
//        void setright(cnode* rightvalue);
//        void setitem(int itemvalue);
//};
//
////생성자
//cnode::cnode(){
//    left = NULL;
//    right = NULL;
//    item = 0;
//}
//cnode::cnode(cnode* leftvalue, cnode* rightvalue, int itemvalue){
//    left = leftvalue;
//    right = rightvalue;
//    item = itemvalue;
//}
//
////멤버 메서드
//void cnode::setleft(cnode* leftvalue){
//    left = leftvalue;
//}
//void cnode::setright(cnode* rightvalue){
//    right = rightvalue;
//}
//void cnode::setitem(int itemvalue){
//    item = itemvalue;
//}
//
//
//
//int main(void){
//    cnode c1();
//    cout << c1.item << endl;
//
//    return 0;
//}