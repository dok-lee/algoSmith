/**
 * 1159 : 농구경기
 * 입력
 * 첫째 줄에 선수의 수 N (1 ≤ N ≤ 150)이 주어진다. 다음 N개 줄에는 각 선수의 성이 주어진다. (성은 알파벳 소문자로만 이루어져 있고, 최대 30글자이다)
 * 출력
 * 누가 선발인지 기억하기 쉽게 하기 위해 성의 첫 글자가 같은 선수 5명을 선발하려고 한다.
 * 상근이가 선수 다섯 명을 선발할 수 없는 경우에는 "PREDAJA" (따옴표 없이)를 출력한다. PREDAJA는 크로아티아어로 항복을 의미한다. 선발할 수 있는 경우에는 가능한 성의 첫 글자를 사전순으로 공백없이 모두 출력한다.
 * @note 출력용 string을 선언해놓고 더하여 한 번에 출력하면 해당 string의 size()를 검사하여 PREDAJA를 출력할 수 있다.
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int playerNum;
    cin >> playerNum;
    cin.ignore();

    int count[26] = {0};
    bool isPossible = false;
    string player;

    for (int i = 0; i < playerNum; i++) {
        getline(cin, player);

        count[player[0] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if (count[i] >= 5) {
            cout << char(i + 'a');
            isPossible = true;
        }
    }

    if (!isPossible) {
        cout << "PREDAJA";
    }

    cout << endl;
}