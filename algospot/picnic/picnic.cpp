#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

vector<vector<int> > getFriends(int studentNumber, int friendNumber);
int countPossiblePairs(vector<vector<int> > &friends, vector<int> &takenStudents);

int main() {

    int cases;
    cin >> cases;
    cin.ignore();

    int studentNumber;
    int friendNumber;

    while (cases--) {
        cin >> studentNumber;
        cin >> friendNumber;

        vector<vector<int> > friends = getFriends(studentNumber, friendNumber);
        vector<int> takenStudents;

        int pairNumber = countPossiblePairs(friends, takenStudents);

        cout << pairNumber << endl;
    }


    return 0;
}

vector<vector<int> > getFriends(int studentNumber, int friendNumber) {
    int firstStudent;
    int secondStudent;
    vector<vector<int> > friends(studentNumber, vector<int>(studentNumber, 0));

    while (friendNumber--) {
        cin >> firstStudent;
        cin >> secondStudent;

        friends[firstStudent][secondStudent] = 1;
        friends[secondStudent][firstStudent] = 1;
    }

    return friends;
}

int countPossiblePairs(vector<vector<int> > &friends, vector<int> &takenStudents) {
    int num = 0;

    // if (takenStudents.size() == friends[0].size()) {
    //     for (int i = 0; i < takenStudents.size(); i++) {
    //         cout << takenStudents[i] << " ";
    //     }
    //     cout << endl;
    // }

    int min = -1;

    for (int i = 0; i < friends[0].size(); i++) {
        if (find(takenStudents.begin(), takenStudents.end(), i) == takenStudents.end()) {
            min = i;
            break;
        }
    }

    if (min == -1) {
        return 1;
    }


    for (int j = min + 1; j < friends[0].size(); j++) {
        if (find(takenStudents.begin(), takenStudents.end(), j) == takenStudents.end()
                && friends[min][j] == 1) {

            takenStudents.push_back(min);
            takenStudents.push_back(j);
            num += countPossiblePairs(friends, takenStudents);

            takenStudents.pop_back();
            takenStudents.pop_back();
        }
    }

    return num;
}