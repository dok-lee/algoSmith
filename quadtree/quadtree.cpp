#include <iostream>
#include <string>

using namespace std;

int cursor;

string invert(string quadtree);

int main() {
    int cases;
    cin >> cases;
    cin.ignore();

    while (cases--) {
        cursor = -1;

        string quadtree;
        getline(cin, quadtree);

        cout << invert(quadtree) << endl;
    }
}

string invert(string quadtree) {
    ++cursor;

    if (quadtree.at(cursor) == 'b' || quadtree.at(cursor) == 'w') {
        string result = "";
        return result + quadtree.at(cursor);
    }

    string first = invert(quadtree);
    string second = invert(quadtree);
    string third = invert(quadtree);
    string fourth = invert(quadtree);

    string result = "x";
    return result + third + fourth + first + second;
}