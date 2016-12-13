#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int R;
    cin >> R; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    std::vector<int> currentLine(1, R);
    std::vector<int> nextLine;
    int counter = 0;
    for ( int i = 0; i < L - 1; i++ ) {
        for ( int j = 0; j < currentLine.size(); j++ ) {
            if ( currentLine[j] == R ) {
                counter++;
                if ( j + 1 == currentLine.size() ) {
                    nextLine.push_back(counter);
                    nextLine.push_back(currentLine[j]);
                }
            } else {
                nextLine.push_back(counter);
                counter = 1;
                nextLine.push_back(R);
                R = currentLine[j];
                if ( j + 1 == currentLine.size() ) {
                    nextLine.push_back(counter);
                    nextLine.push_back(currentLine[j]);
                }
            }
        }
        currentLine.clear();
        currentLine.swap(nextLine);
        R = currentLine[0];
        counter = 0;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int lastIndex = currentLine.size() - 1;
    for(int i = 0; i < lastIndex; i++) {
        cout << currentLine[i] << ' ';
    }
    cout << currentLine[lastIndex] << endl;

    return 0;
}
