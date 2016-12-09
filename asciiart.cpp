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
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    vector<string> ascii;
    vector<string>::iterator it;

    vector<string> answer;

    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        ascii.push_back(ROW);
    }
    for (int i = 0; i < (int)T.size(); i++) {
        T[i] = toupper(T[i]);
    }

    for ( it = ascii.begin(); it != ascii.end(); it++ ) {
        string temp = *it;
        string answ;
        for ( int j = 0; j < T.size(); j++ ) {
            int tmp = (T[j] - 65) * L;
            if ( tmp >= 0 && tmp <= (90 - 65) * L ) {
                answ += temp.substr(tmp, L);
            } else {
                answ += temp.substr(temp.size()-L, L);
            }
        }
        answer.push_back(answ);
    }

    for ( it = answer.begin(); it != answer.end(); it++ ) {
        cout << *it << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
}
