#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    string MESSAGE;
    getline(cin, MESSAGE);

    int size = MESSAGE.size();
    string bitStr = "";

    for ( int i = 0; i < size; i++ ) {
        bitset<7>bitset = MESSAGE[i];
        string temp = bitset.to_string<char, std::char_traits<char>, std::allocator<char> >();
        bitStr += temp;
    }

    string answer = "";
    int zero = -1;
    string tmp = "";

    for ( string::iterator it = bitStr.begin(); it != bitStr.end(); it++ ) {
        int newZero = (*it == '0');

        if ( newZero == zero ) {
            tmp += "0";
        } else {
            zero = newZero;
            if ( answer.size() > 0 ) {
                answer += " ";
            }
            answer += tmp;
            if(zero) {
                tmp = "00 0";
            } else {
                tmp = "0 0";
            }
        }
    }

    if(tmp.size() > 0) {
        if(answer.size() > 0) {
            answer += " ";
        }
        answer += tmp;
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << answer << endl;
    
    return 0;
}
