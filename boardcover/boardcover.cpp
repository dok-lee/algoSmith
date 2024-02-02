#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

void getBoard(int height, vector<string> &board);
bool isCoverable(vector<string> &board);
int coverTile(vector<string> &board, int cursorX, int cursorY);

// not completed
int main() {

    int cases;
    cin >> cases;

    while (cases--) {
        int height;
        int width;

        cin >> height;
        cin >> width;
        cin.ignore();

        vector<string> board;
        getBoard(height, board);

        if (!isCoverable(board)) {
            cout << 0 << endl;
            continue;
        }


    }

    return 0;
}

void getBoard(int height, vector<string> &board) {
    for (int i = 0; i < height; i++) {
        string line;

        getline(cin, line);
        board.push_back(line);
    }
}

bool isCoverable(vector<string> &board) {
    int count = 0;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '.') {
                count++;
            }
        }
    }

    if (count % 3 == 0) {
        return true;
    } else {
        return false;
    }
}

int coverTile(vector<string> &board, int cursorX, int cursorY) {
    int count = 0;

    if (board[cursorX][cursorY] != '.') {
        return 0;
    }


    if (board[cursorX + 1][cursorY] == '.' && board[cursorX + 1][cursorY + 1] == '.') {
        board[cursorX][cursorY] = '#';
        board[cursorX + 1][cursorY] = '#';
        board[cursorX + 1][cursorY + 1] = '#';

        count += coverTile(board, cursorX, cursorY);

        board[cursorX][cursorY] = '.';
        board[cursorX + 1][cursorY] = '.';
        board[cursorX + 1][cursorY + 1] = '.';
    }
    if (board[cursorX + 1][cursorY] == '.' && board[cursorX][cursorY + 1] == '.') {

    }
    if (board[cursorX][cursorY + 1] == '.' && board[cursorX - 1][cursorY + 1] == '.') {

    }
    if (board[cursorX][cursorY + 1] == '.' && board[cursorX + 1][cursorY + 1] == '.') {

    }
}