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
    vector<int> values;
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v; cin.ignore();
        values.push_back(v);
    }

    int maxLosses = 0;
    int lastMaxUp = 0;
    for ( int i = maxLosses + 1; i < n; i++ ) {
        int tmp = values[i] - values[lastMaxUp];
        if ( tmp < 0 && tmp < maxLosses ) {
            maxLosses = tmp;
        } else if ( tmp > 0 ) {
            lastMaxUp = i;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << maxLosses << endl;
    
    return 0;
}
