/**
 * 1629 : 곱셈
 * 문제
 * 자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.
 * 입력
 * 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.
 * 출력
 * 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
 * 예제 입력 1
 * 10 11 12
 * 예제 출력 1
 * 4
 * @note n번 곱하는 동작을 log2 n번 곱해서 처리하기
 * @note (a + b) % c = (a % c) + (b % c), (a * b) % c = (a % c) * (b % c) 임을 이용해 자료형 최대 범위보다 큰 값이 발생하지 않도록 하기
 * @note 홀수번 곱하는 경우를 생각해서 따로 처리해주기
*/

#include <iostream>
using namespace std;

long long multiSquareModular(long long num, long long times, int division) {
    if (times == 1 || times == 0) {
        return num % division;
    }

    long long result = multiSquareModular(num, times / 2, division);
    result = (result * result) % division;

    if (times % 2 == 1) {
        result = result * num % division;
    }

    return result;
}

int main() {
    long long num;
    long long times;
    long long division;

    cin >> num;
    cin >> times;
    cin >> division;

    cout << multiSquareModular(num, times, division) << endl;
}