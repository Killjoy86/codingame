#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Point {
    public:
        double longitude;
        double latitude;

        Point() {
            longitude = 0;
            latitude = 0;
        }

        Point(string lon, string lat) {
            int pos = lon.find(',');
            lon[pos] = '.';
            this->longitude = stod(lon);

            pos = lat.find(',');
            lat[pos] = '.';
            this->latitude = stod(lat);
        }

        static double distance(const Point& A, const Point& B);
};

double Point::distance(const Point& A, const Point& B) {
    double x = (B.longitude - A.longitude) * cos((A.latitude + B.latitude) / 2);
    double y = B.latitude - A.latitude;
    double d = sqrt(pow(x,2) + pow(y,2)) * 6371;

    return d;
}

class Defibrillators {
    public:
        Defibrillators(string script);
        string numId;
        string name;
        string address;
        string contacPhone;
        Point location;
};

Defibrillators::Defibrillators(string script) {
    vector<string> properties;
    stringstream ss(script);
    string tmp;
    while( getline(ss, tmp, ';') ) {
        properties.push_back(tmp);
    }

    this->numId = properties[0];
    this->name = properties[1];
    this->address = properties[2];
    this->contacPhone = properties[3];
    string defLon = properties[4];
    string defLat = properties[5];
    Point defLocation(defLon, defLat);
    this->location = defLocation;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    Point userLocation(LON, LAT);
    int N;
    cin >> N; cin.ignore();
    vector<Defibrillators*> defibrillators;
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        defibrillators.push_back(new Defibrillators(DEFIB));
    }

    double counter = -1;
    string nearest;
    for ( int i = 0; i < N; i++ ) {
        double tmp = Point::distance(userLocation, defibrillators[i]->location);
        if ( (counter == -1) || tmp < counter ) {
            counter = tmp;
            nearest = defibrillators[i]->name;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << nearest << endl;

    for ( int i = 0; i < N; i++ ) {
        delete defibrillators[i];
    }

    return 0;
}
