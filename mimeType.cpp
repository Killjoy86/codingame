#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    map<string, string> table;
    map<string, string>::iterator it = table.begin();

    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        std::transform(EXT.begin(), EXT.end(), EXT.begin(), ::tolower);
        table.insert(it, pair<string, string>(EXT, MT));
        it++;
    }

    vector<string> files;
    vector<string>::iterator itVec;
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        std::transform(FNAME.begin(), FNAME.end(), FNAME.begin(), ::tolower);
        files.push_back(FNAME);
    }

    for ( itVec = files.begin(); itVec != files.end(); itVec++ ) {
        string tmpFiles = *itVec;
        size_t dot = tmpFiles.rfind('.');
        if ( dot == -1 ) {
            cout << "UNKNOWN" << endl;
        } else {
            string tmpExt = tmpFiles.substr(dot+1);
            it = table.find(tmpExt);
            if ( it == table.end() ) {
                cout << "UNKNOWN" << endl;
            } else {
                cout << it->second << endl;
            }
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    return 0;
}
