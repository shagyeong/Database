//다차원 배열 예제
//학생의 퀴즈 점수를 이차원 배열에 저장
#include<iostream>
#include<iomanip>
using namespace std;

const int NOS = 7; //the number of students : 학생 수
const int NOQ = 3; //the number of quizes : 퀴즈 수

void computesavg(const int scores[NOS][NOQ], double savg[]);
void computeqavg(const int scores[NOS][NOQ], double qavg[]);
void display(const int scores[NOS][NOQ],
             const double savg[],
             const double qavg[]);

int main(void){
    int scores[NOS][NOQ];
    double savg[NOS]; //학생 평균
    double qavg[NOQ]; //문항 당 평균

    scores[0][0] = 8; scores[0][1] = 1; scores[0][2] = 4;
    scores[1][0] = 7; scores[1][1] = 6; scores[1][2] = 7;
    scores[2][0] = 5; scores[2][1] = 4; scores[2][2] = 9;
    scores[3][0] = 4; scores[3][1] = 7; scores[3][2] = 2;
    scores[4][0] = 3; scores[4][1] = 9; scores[4][2] = 4;
    scores[5][0] = 9; scores[5][1] = 2; scores[5][2] = 6;
    scores[6][0] = 1; scores[6][1] = 6; scores[6][2] = 3;
    
    computesavg(scores, savg);
    computeqavg(scores, qavg);

    display(scores, savg, qavg);

    return 0;
}

//axis0 : 학생 순회 인덱스
//axis1 : 퀴즈 순회 인덱스
void computesavg(const int scores[NOS][NOQ], double savg[]){  
    for(int axis0 = 0; axis0 < NOS; axis0++){
        double sum = 0;

        for(int axis1 = 0; axis1 < NOQ; axis1 ++){
            sum += scores[axis0][axis1];
        }

        savg[axis0] = sum / NOQ;
    }
}
void computeqavg(const int scores[NOS][NOQ], double qavg[]){
    for(int axis1 = 0; axis1 < NOQ; axis1++){
        double sum = 0;

        for(int axis0 = 0; axis0 < NOS; axis0++){
            sum += scores[axis0][axis1];
        }

        qavg[axis1] = sum / NOS;
    }
}

void display(const int scores[NOS][NOQ],
             const double savg[],
             const double qavg[]){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //setw는 매개변수의 수만큼 공백을 출력
    cout << setw(10) << "student"
         << setw(5) << "avg"
         << setw(15) << "quizzes\n";
    
    for(int axis0 = 0; axis0 < NOS; axis0++){
        cout << setw(10) << axis0 //학생 번호
             << setw(5) << savg[axis0] << " ";
        
        for(int axis1 = 0; axis1 < NOQ; axis1++){
            cout << setw(5) << scores[axis0][axis1];
        }

        cout << endl;
    }

    cout << "quiz avg" << endl;

    for(int axis1 = 0; axis1 < NOQ; axis1++){
        cout << setw(5) << qavg[axis1];
    }

    cout << endl;
}
