#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

class Point {
    public:
        int x;
        int y;

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }
};

const Point south(0, 1);
const Point east(1, 0);
const Point north(0, -1);
const Point west(-1, 0);

class Bender {
    public:
        int x;
        int y;
        bool isBreakerMode = false;
        bool isInverted = false;
        string directionToMove = "SOUTH";

        bool operator == (const Bender& bender) const {
            return ((x == bender.x) && (y == bender.y) &&
                    (isBreakerMode == bender.isBreakerMode) && 
                    (isInverted == bender.isInverted) &&
                    (directionToMove == bender.directionToMove));
        }
};

map<pair<int, int>, vector<Bender>> places;

string dirToStr(Point point) {
    if ( point.x == 0 ) {
        if ( point.y == 1 ) {
            return "SOUTH";
        } else {
            return "NORTH";
        }
    } else {
        if ( point.x == 1 ) {
            return "EAST";
        } else {
            return "WEST";
        }
    }
}

string move(vector<vector<char>>& field, Bender& bender) {
    vector<Point> directions;

    if ( !bender.isInverted ) {
        directions = {south, east, north, west};
    } else {
        directions = {west, north, east, south};
    }

    for ( int i = 0; i < directions.size(); i++ ) {
        if ( field[bender.y + directions[i].y][bender.x + directions[i].x] != 'X' &&
             field[bender.y + directions[i].y][bender.x + directions[i].x] != '#' ) {
            bender.x += directions[i].x;
            bender.y += directions[i].y;
            bender.directionToMove = dirToStr(directions[i]);
            return bender.directionToMove;
        }
    }
}

string makeStep(Point point, vector<vector<char>>& field, Bender& bender) {
    if ( field[bender.y + point.y][bender.x + point.x] == 'X' ) {
        if ( bender.isBreakerMode ) {
            field[bender.y + point.y][bender.x + point.x] = ' ';
            places.clear();
        } else {
            return move(field, bender);
        }
    } else if ( field[bender.y + point.y][bender.x + point.x] == '#' ) {
        return move(field, bender);
    }
    bender.x += point.x;
    bender.y += point.y;
    return dirToStr(point);
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    Bender bender;
    vector<vector<char>> field;
    vector<string> steps;
    vector<Point*> teleports;

    int L;
    int C;
    cin >> L >> C; cin.ignore();

    for (int i = 0; i < L; i++) {
        string row;
        getline(cin, row);

        field.push_back({});
        for ( int j = 0; j < C; j++ ) {
            field.back().push_back(row[j]);
            if ( row[j] == '@' ) {
                bender.x = j;
                bender.y = i;
            } else if ( row[j] == 'T' ) {
                teleports.push_back(new Point(j, i));
            }
        }
    }

    assert( teleports.size() == 0 || teleports.size() == 2 );

    while ( field[bender.y][bender.x] != '$' ) {
        if (places.find({bender.x, bender.y}) != places.end()) {
            if (find(places[{bender.x, bender.y}].begin(),
                          places[{bender.x, bender.y}].end(),
                          bender) != places[{bender.x, bender.y}].end()) {
                cout << "LOOP" << std::endl;
                return 0;
            }
        }
        places[{bender.x, bender.y}].push_back(bender);
        
        switch(field[bender.y][bender.x]) {
            case 'N':
                bender.directionToMove = "NORTH";
                break;
            case 'E':
                bender.directionToMove = "EAST";
                break;
            case 'S':
                bender.directionToMove = "SOUTH";
                break;
            case 'W':
                bender.directionToMove = "WEST";
                break;
            case 'I':
                bender.isInverted = !bender.isInverted;
                break;
            case 'B':
                bender.isBreakerMode = !bender.isBreakerMode;
                break;
            case 'T':
                if ((bender.x == teleports[0]->x) && (bender.y == teleports[0]->y)) {
                    bender.x = teleports[1]->x;
                    bender.y = teleports[1]->y;
                } else {
                    bender.x = teleports[0]->x;
                    bender.y = teleports[0]->y;
                }
                break;

        }
        if ( bender.directionToMove == "NORTH" ) {
            steps.push_back(makeStep(north, field, bender));
        } else if ( bender.directionToMove == "EAST" ) {
            steps.push_back(makeStep(east, field, bender));
        } else if ( bender.directionToMove == "SOUTH" ) {
            steps.push_back(makeStep(south, field, bender));
        } else if ( bender.directionToMove == "WEST" ) {
            steps.push_back(makeStep(west, field, bender));
        }
    }

    for( int i = 0; i < steps.size(); i++ ) {
        cout << steps[i] << endl;
    }
    
    if ( teleports.size() == 2 ) {
        for ( auto& tele : teleports ) {
            delete tele;
        }
    }

    return 0;
}
