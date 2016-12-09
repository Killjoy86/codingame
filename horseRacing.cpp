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
    int N;
    cin >> N; cin.ignore();
    vector<int> horses;
    vector<int>::iterator it;

    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horses.push_back(Pi);
    }

    sort(horses.begin(), horses.end());

    int answer = 100000;
    for ( it = horses.begin() + 1; it < horses.end(); it++ ) {
        if ( answer > (*it - *(it-1)) ) {
            answer = *it - *(it-1);
        }
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << answer << endl;
    
    return 0;
}
