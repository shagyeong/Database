//append(이어적기)
#include<fstream>
using std::ofstream;
using std::ios;
using std::endl;

int main(void){
    ofstream ostream;
    ostream.open("outfile.txt", ios::app);

    ostream << "append!" << endl;

    ostream.close();

    return 0;
}