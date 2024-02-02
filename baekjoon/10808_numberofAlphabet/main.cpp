/**
 * 10808 : 알파벳 개수
 *
 * 입력
 * 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.
 * 출력
 * 단어에 포함되어 있는 a의 개수, b의 개수, …, z의 개수를 공백으로 구분해서 출력한다.
*/

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int alphabet[26] = {0};

    string word;
    cin >> word;

    for (int i = 0; i < word.size(); i++) {
        int ascii = int(word[i]) - 97;

        alphabet[ascii]++;
    }

    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }

    cout << endl;
}