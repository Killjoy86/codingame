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
    int C;
    cin >> C; cin.ignore();
    int sum = 0;
    vector<int> list;
    vector<int>::iterator it;
    for (int i = 0; i < N; i++) {
        int B;
        cin >> B; cin.ignore();
        list.push_back(B);
        sum += B;
    }

    if ( sum < C ) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    sort(list.begin(), list.end());

    int oods = N;
    int cost = C;
    for ( ; oods > 0; ) {
        int average = cost / oods;
        int remnant = cost % oods;
        bool isAverageRecalc = true;
        for ( int i = N - oods; i < N; i++ ) {
            if ( list[i] < average ) {
                cost -= list[i];
                oods--;
                cout << list[i] << endl;
                isAverageRecalc = false;
            } else {
                if (isAverageRecalc) {
                    for ( int j = i; j < N - remnant; j++ ) {
                        cout << average << endl;
                    }
                    for ( int j = N - remnant; j < N; j++ ) {
                        cout << average + 1 << endl;
                    }
                    oods = 0;
                    break;
                }
            }
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    return 0;
}
