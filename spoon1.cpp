#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main() {
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    char array[height][width];
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        for ( int j = 0; j < line.size(); j++ ) {
            array[i][j] = line[j];
        }
    }

    string coordinate = "";
    string coordinateNodeRight = "";
    string coordinateNodeBottom = "";

    for ( int i = 0; i < height; i++ ) {
        for ( int j = 0; j < width; j++ ) {
            if ( array[i][j] == '0' ) {
                coordinate = to_string(j) + ' ' + to_string(i) + ' ';
                coordinateNodeRight = "";
                for ( int k = 1; k+j < width; k++ ) {
                    if ( array[i][j+k] == '0' ) {
                        coordinateNodeRight = to_string(j+k) + ' ' + to_string(i) + ' ';
                        break;
                    }
                }
                if ( coordinateNodeRight == "" ) {
                    coordinateNodeRight = "-1 -1 ";
                }
                coordinateNodeBottom = "";
                for ( int k = 1; k+i < height; k++ ) {
                    if ( array[i+k][j] == '0' ) {
                        coordinateNodeBottom = to_string(j) + ' ' + to_string(i+k);
                        break;
                    }
                }
                if ( coordinateNodeBottom == "" ) {
                    coordinateNodeBottom = "-1 -1";
                }
                cout << coordinate << coordinateNodeRight << coordinateNodeBottom << endl;
            } else {
                coordinate = "-1 -1 ";
            }
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    return 0;
}
