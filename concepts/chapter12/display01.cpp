#include<fstream>
using std::ifstream;
using std::ofstream;
using std::endl;

int main(void){
    ifstream istream;
    ofstream ostream;

    istream.open("infile.txt");
    ostream.open("outfile.txt");

    int i1;
    int i2;
    int i3;

    istream >> i1;
    istream >> i2;
    istream >> i3;

    ostream << i1 << " + " << i2 << " + " << i3 << " = "
            << i1 + i2 + i3 << endl;
    istream.close();
    ostream.close();

    return 0;
}