/**
 * 4375 : 1
 * 문제
 * 2와 5로 나누어 떨어지지 않는 정수 n(1 ≤ n ≤ 10000)가 주어졌을 때, 각 자릿수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램을 작성하시오.
 * 입력
 * 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다.
 * 출력
 * 각 자릿수가 모두 1로만 이루어진 n의 배수 중 가장 작은 수의 자리수를 출력한다.
 * @note 9999 등 1로만 이루어진 배수가 long long의 범위를 벗어나는 케이스가 존재한다. 모듈러 연산을 분할하는 것이 필요. (a + b) % c = (a % c) + (b % c)
 * @note while(scanf("%d", &x) != EOF)는 백준에서 end of file을 처리하기 위한 방법.
 * 예제 입력 1
3
7
9901
 * 예제 출력 1
3
6
12
*/

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int countOnes(string oneStr, int divider) {
//     unsigned long long ones = stoull(oneStr);

//     if (ones % divider == 0) {
//         return oneStr.size();
//     } else {
//         return countOnes(oneStr.append("1"), divider);
//     }
// }

// int main() {
//     while (true) {
//         int num;
//         cin >> num;

//         int size = countOnes("1", num);

//         cout << size << endl;
//     }
// }

#include <iostream>
using namespace std;

int countOnes(int divider) {
    int i = 1;
    int num = 1;
    int modular = num % divider;

    while (true) {
        modular %= divider;

        if (modular == 0) {
            return i;
        } else {
            modular *= 10;
            modular += 1;
            i++;
        }
    }
}

int main() {
    int num;

    while (scanf("%d", &num) != EOF) {
        int size = countOnes(num);

        cout << size << endl;
    }
}