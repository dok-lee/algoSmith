#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

#define ROW 5
#define COLUMN 5

bool isBoggleAble(string word, char boggleBoard[][COLUMN]);
bool doesNextCharExist(string word, int step, char boggleBoard[][COLUMN], int cur_row, int cur_column);

int main() {

    int cases;
    cin >> cases;
    cin.ignore();

    char boggleBoard[ROW][COLUMN];

    while (cases--) {
        string rowString = "";

        for (int i = 0; i < ROW; i++) {
            getline(cin, rowString);

            for (int j = 0; j < COLUMN; j++) {
                boggleBoard[i][j] = rowString[j];
            }
        }

        int word_number;

        cin >> word_number;
        cin.ignore();

        vector<string> words;

        for (int i = 0; i < word_number; i++) {
            string word;

            getline(cin, word);
            words.push_back(word);
        }

        for (int i = 0; i < word_number; i++) {
            string word = words.at(i);

            if (isBoggleAble(word, boggleBoard)) {
                cout << word << " YES" << endl;
            } else {
                cout << word << " NO" << endl;
            }
        }
    }

    return 0;
}

bool isBoggleAble(string word, char boggleBoard[][COLUMN]) {
    int step = 0;
    bool boggleAble = false;

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (word.at(step) == boggleBoard[i][j]) {
                boggleAble = doesNextCharExist(word, step + 1, boggleBoard, i, j);

                if (boggleAble == true) {
                    return boggleAble;
                }
            }
        }
    }

    return boggleAble;
}

bool doesNextCharExist(string word, int step, char boggleBoard[][COLUMN], int cur_row, int cur_column) {
    if (step == word.length()) {
        return true;
    }

    if (cur_row > 0 && cur_column > 0 && boggleBoard[cur_row - 1][cur_column - 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row - 1, cur_column - 1);
    } else if (cur_row > 0 && boggleBoard[cur_row - 1][cur_column] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row - 1, cur_column);
    } else if (cur_row > 0 && cur_column < COLUMN - 1 && boggleBoard[cur_row - 1][cur_column + 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row - 1, cur_column + 1);
    } else if (cur_column > 0 && boggleBoard[cur_row][cur_column - 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row, cur_column - 1);
    } else if (cur_column < COLUMN - 1 && boggleBoard[cur_row][cur_column + 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row, cur_column + 1);
    } else if (cur_row < ROW - 1 && cur_column > 0 && boggleBoard[cur_row + 1][cur_column - 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row + 1, cur_column - 1);
    } else if (cur_row < ROW - 1 && boggleBoard[cur_row + 1][cur_column] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row + 1, cur_column);
    } else if (cur_row < ROW - 1 && cur_column < COLUMN - 1 && boggleBoard[cur_row + 1][cur_column + 1] == word[step]) {
        return doesNextCharExist(word, step + 1, boggleBoard, cur_row + 1, cur_column + 1);
    } else {
        return false;
    }
}