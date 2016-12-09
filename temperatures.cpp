#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

#define MIN -273

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    istringstream iss(temps);

    int result = 5526;

    if ( n == NULL || n < 0 ) {
        cout << "0" << endl;
        return 0;
    }

    for ( int i = 0; i < n; i++ ) {
        int tmp;
        iss >> tmp;
        if ( n == 1 && tmp < MIN ) {
            cout << "0" << endl;
            return 0;
        }
        if( tmp == 0 ) {
            break;
        }
        if ( (abs(tmp) < abs(result)) && tmp >= MIN ) {
            result = tmp;
        } else if ( (abs(tmp) == abs(result)) && (tmp == -result) ) {
            result = abs(result);
        }
    }
    cout << result << endl;
    
    return 0;
}
