#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
/////////////////////////////////////////////////////////////////
    char array[H][W];
    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            array[i][j] = '.';
        }
    }
    array[3][7] = 'B';
    array[X0][Y0] = 'M';

    for ( int i = 0; i < H; i++ ) {
        for ( int j = 0; j < W; j++ ) {
            cout << array[j][i] << ' ';
        }
        cout << endl;
    }
/////////////////////////////////////////////////////////////////

    int horizontal = X0;
    int vertical = Y0;
    int width, height;
    bool isFirstStep = true;
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        if ( isFirstStep ) {
            if ( bombDir == "UR" ) {
                width = W - X0;
                height = Y0;
            } else if ( bombDir == "UL" ) {
                width = X0;
                height = Y0;
            } else if ( bombDir == "DR" ) {
                width = W - X0;
                height = H - Y0;
            } else if ( bombDir == "DL" ) {
                width = X0;
                height = H - Y0;
            } else if ( bombDir == "U" ) {
                width = 0;
                height = Y0;
            } else if ( bombDir == "D" ) {
                width = 0;
                height = H - Y0;
            } else if ( bombDir == "L" ) {
                width = X0;
                height = 0;
            } else if ( bombDir == "R" ) {
                width = W - X0;
                height = 0;
            }
            isFirstStep = false;
        }

        if ( bombDir == "UR" ) {
            X0 = horizontal + ceil(width / 2.0);
            Y0 = vertical - ceil(height / 2.0);
        } else if ( bombDir == "DR" ) {
            X0 = horizontal + ceil(width / 2.0);
            Y0 = vertical + ceil(height / 2.0);
        } else if ( bombDir == "DL" ) {
            X0 = horizontal - ceil(width / 2.0);
            Y0 = vertical + ceil(height / 2.0);
        } else if ( bombDir == "UL" ) {
            X0 = horizontal - ceil(width / 2.0);
            Y0 = vertical - ceil(height / 2.0);
        } else if ( bombDir == "U" ) {
            Y0 = vertical - ceil(height / 2.0);
        } else if ( bombDir == "D" ) {
            Y0 = vertical + ceil(height / 2.0);
        } else if ( bombDir == "L" ) {
            X0 = horizontal - ceil(width / 2.0);
        } else if ( bombDir == "R" ) {
            X0 = horizontal + ceil(width / 2.0);
        }

        if ( bombDir == "UR" || bombDir == "DR" || bombDir == "DL" || bombDir == "UL" ) {
            horizontal = X0;
            vertical = Y0;
            width /= 2;
            height /= 2;
        } else if ( bombDir == "U" || bombDir == "D" ) {
            vertical = Y0;
            width = 1;
            height /= 2;
        } else if ( bombDir == "L" || bombDir == "R" ) {
            horizontal = X0;
            width /= 2;
            height = 1;
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // the location of the next window Batman should jump to.
        cout << X0 << ' ' << Y0 << endl;
        if ( array[X0][Y0] == 'B' ) {
            return 0;
        }
    }

    return 0;
}
