/**
 * 10988 : 팰린드롬인지 확인하기
 *
 * 입력
 * 첫째 줄에 단어가 주어진다. 단어의 길이는 1보다 크거나 같고, 100보다 작거나 같으며, 알파벳 소문자로만 이루어져 있다.
 * 출력
 * 첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.
 * @note STL 중 reverse()를 활용하면 알고리즘을 구현하지 않아도 된다. reverse()는 원본 배열을 직접 뒤집음에 유의.
*/

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    for (int i = 0; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    string word;
    cin >> word;

    cout << isPalindrome(word) << endl;
}