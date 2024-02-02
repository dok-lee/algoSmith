/**
 * 2979 : 트럭 주차
 *
 * 입력
 * 첫째 줄에 문제에서 설명한 주차 요금 A, B, C가 주어진다. (1 ≤ C ≤ B ≤ A ≤ 100)
 * 다음 세 개 줄에는 두 정수가 주어진다. 이 정수는 상근이가 가지고 있는 트럭이 주차장에 도착한 시간과 주차장에서 떠난 시간이다. 도착한 시간은 항상 떠난 시간보다 앞선다. 입력으로 주어지는 시간은 1과 100사이 이다.
 * 출력
 * 첫째 줄에 상근이가 내야하는 주차 요금을 출력한다.
*/

#include <iostream>
using namespace std;

void fillTimeTable(int arriveTime, int leaveTime, int timeTable[]) {
    for (int i = arriveTime; i < leaveTime; i++) {
        timeTable[i]++;
    }
}

int main() {
    int timeTable[100] = {0};
    int singlePayment, doublePayment, triplePayment;
    int aArriveTime, bArriveTime, cArriveTime;
    int aLeaveTime, bLeaveTime, cLeaveTime;

    cin >> singlePayment >> doublePayment >> triplePayment;
    cin >> aArriveTime >> aLeaveTime;
    cin >> bArriveTime >> bLeaveTime;
    cin >> cArriveTime >> cLeaveTime;

    fillTimeTable(aArriveTime, aLeaveTime, timeTable);
    fillTimeTable(bArriveTime, bLeaveTime, timeTable);
    fillTimeTable(cArriveTime, cLeaveTime, timeTable);

    int sum = 0;

    for (int i = 0; i < 100; i++) {
        if (timeTable[i] == 1) {
            sum += singlePayment;
        } else if (timeTable[i] == 2) {
            sum += doublePayment * 2;
        } else if (timeTable[i] == 3) {
            sum += triplePayment * 3;
        }
    }

    cout << sum << endl;
}