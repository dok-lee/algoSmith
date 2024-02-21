/**
 * 2559 : 수열
 * 입력
 * 첫째 줄에는 두 개의 정수 N과 K가 한 개의 공백을 사이에 두고 순서대로 주어진다.
 * 첫 번째 정수 N은 온도를 측정한 전체 날짜의 수이다. N은 2 이상 100,000 이하이다.
 * 두 번째 정수 K는 합을 구하기 위한 연속적인 날짜의 수이다. K는 1과 N 사이의 정수이다.
 * 둘째 줄에는 매일 측정한 온도를 나타내는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 수들은 모두 -100 이상 100 이하이다.
 * 출력
 * 첫째 줄에는 입력되는 온도의 수열에서 연속적인 K일의 온도의 합이 최대가 되는 값을 출력한다.
 * @note 구간합 계산을 1초 내에 해결해야하는 문제, 주석처리된 최초 풀이처럼 이중 for문으로 구간합을 새로 만들면 시간 내에 해결할 수 없음.
*/

#include <iostream>
// #include <vector>
#include <algorithm>
using namespace std;

int main() {
    int days, dayContinous, temp, dayPsum[100001] = {0}, ret = -10000004;

    cin >> days;
    cin >> dayContinous;
    for (int i = 1; i <= days; i++) {
        cin >> temp;
        dayPsum[i] = dayPsum[i - 1] + temp;
    }

    for (int i = dayContinous; i <= days; i++) {
        ret = max(ret, dayPsum[i] - dayPsum[i - dayContinous]);
    }

    cout << ret << "\n";
    return 0;
}

// vector<int> sumContinous(vector<int> days, int dayContinous) {
//     vector<int> daySum;

//     for (int i = 0; i < days.size() - dayContinous + 1; i++) {
//         int sum = 0;

//         for (int j = i; j < i + dayContinous; j++) {
//             sum += days[j];
//         }

//         daySum.push_back(sum);
//     }

//     return daySum;
// }

// int main() {
//     int dayTotal;
//     int dayContinous;

//     cin >> dayTotal;
//     cin >> dayContinous;

//     vector<int> days;

//     for (int i = 0; i < dayTotal; i++) {
//         int day;
//         cin >> day;

//         days.push_back(day);
//     }

//     vector<int> daySum = sumContinous(days, dayContinous);

//     cout << *max_element(daySum.begin(), daySum.end()) << endl;
// }