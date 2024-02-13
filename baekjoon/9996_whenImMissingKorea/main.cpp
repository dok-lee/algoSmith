/**
 * 9996 : 한국이 그리울 땐 서버에 접속하지
 * 입력
 * 첫째 줄에 파일의 개수 N이 주어진다. (1 ≤ N ≤ 100)
 * 둘째 줄에는 패턴이 주어진다. 패턴은 알파벳 소문자와 별표(아스키값 42) 한 개로 이루어져 있다. 문자열의 길이는 100을 넘지 않으며, 별표는 문자열의 시작과 끝에 있지 않다.
 * 다음 N개 줄에는 파일 이름이 주어진다. 파일 이름은 알파벳 소문자로만 이루어져 있고, 길이는 100을 넘지 않는다.
 * 출력
 * 총 N개의 줄에 걸쳐서, 입력으로 주어진 i번째 파일 이름이 패턴과 일치하면 "DA", 일치하지 않으면 "NE"를 출력한다.
 * 참고로, "DA"는 크로아티어어로 "YES"를, "NE"는 "NO"를 의미한다.
*/

#include <iostream>
#include <string>
using namespace std;

bool isPatternedFileName(string pattern, string fileName) {
    int starIndex = pattern.find('*');

    string patternFront = pattern.substr(0, starIndex);
    string patternBack = pattern.substr(starIndex + 1);

    if (fileName.size() < patternFront.size() + patternBack.size()) {
        return false;
    }

    string fileNameFront = fileName.substr(0, patternFront.size());
    string fileNameBack = fileName.substr(fileName.size() - patternBack.size());

    if ((patternFront.compare(fileNameFront) == 0) && (patternBack.compare(fileNameBack) == 0)) {
        return true;
    }

    return false;
}

int main() {
    int cases;
    cin >> cases;
    string pattern;
    cin >> pattern;

    while (cases--) {
        string fileName;
        cin >> fileName;

        if (isPatternedFileName(pattern, fileName)) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}