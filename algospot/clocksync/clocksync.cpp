#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

#define CLOCKNUM 16
const vector<vector<int> > buttons = {{0, 1, 2},
                                    {3, 7, 9, 11},
                                    {4, 10, 14, 15},
                                    {0, 4, 5, 6, 7},
                                    {6, 7, 8, 10, 12},
                                    {0, 2, 14, 15},
                                    {3, 14, 15},
                                    {4, 5, 7, 14, 15},
                                    {1, 2, 3, 4, 5},
                                    {3, 4, 5, 9, 13}};

void pressButton(int button, vector<int> &clockTimes) {
    vector<int> targetClocks = buttons[button];

    for (int targetClock : targetClocks) {
        clockTimes[targetClock] += 3;
        if (clockTimes[targetClock] > 12) {
            clockTimes[targetClock] -= 12;
        }
    }
}

bool isAligned(vector<int> &clockTimes) {
    for (int i = 0; i < CLOCKNUM; i++) {
        if (clockTimes[i] != 12) {
            return false;
        }
    }

    return true;
}

int countPress(vector<int> &clockTimes) {
    int count = 0;

    if (isAligned(clockTimes)) {
        return 1;
    }

    for ()

    return count;
}

int main() {
    int cases;
    cin >> cases;

    while (cases--) {
        vector<int> clockTimes;

        for (int i = 0; i < CLOCKNUM; i++) {
            cin >> i;
            clockTimes.push_back(i);
        }


    }
}