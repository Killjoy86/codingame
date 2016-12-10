#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>

using namespace std;

class Point {
public:
    Point(int x, int y);
    ~Point();
    int x;
    int y;
};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}
Point::~Point(){
    delete this;
}

bool compareX(const Point* a, const Point* b) {
    return a->x < b->x;
}
bool compareY(const Point* a, const Point* b) {
    return a->y < b->y;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    vector<Point*> buildings;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        buildings.push_back(new Point(X, Y));
    }

    sort(buildings.begin(), buildings.end(), *compareY);

    int mainCableY;
    if ( buildings.size() % 2 == 0 ) {
        mainCableY = buildings[buildings.size() / 2]->y;
    } else {
        mainCableY = (buildings[(buildings.size() / 2)]->y + buildings[buildings.size() / 2]->y) / 2;
    }

    sort(buildings.begin(), buildings.end(), *compareX);

    int minX = buildings.front()->x;
    int maxX = buildings.back()->x;

    long long int cableLenght = maxX - minX;
    for ( int i = 0; i < N; i++ ) {
        cableLenght += abs(mainCableY - buildings[i]->y);
    }
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cout << cableLenght << endl;

    return 0;
}
