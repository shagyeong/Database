//인수 생략 예제
#include<iostream>
using namespace std;

void showvolume(int length, int width = 1, int height = 1);

int main(void){
    showvolume(4, 5, 6);
    showvolume(4, 5   );
    showvolume(4      );

    return 0;
}

void showvolume(int length, int width, int height){
    int volume = length * width * height;

    cout << "length : " << length << endl;
    cout << "width : " << width << endl;
    cout << "height : " << height << endl;
    cout << "volume : " << volume << endl << endl;
}