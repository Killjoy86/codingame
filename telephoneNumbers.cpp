#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Node{
    public:
        map<int, Node*>children;
};

Node* parent;
int counter;

void addTelephone(string& telephone) {
    Node* node = parent;
    for( int i = 0; i < telephone.size(); ++i ){
        int number = telephone.at(i);
        map<int, Node*>::iterator it = node->children.find(number);
        if( it == node->children.end() ){
            node->children[number] = new Node();
            counter++;
        }
        node = node->children[number];
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int N;
    counter = 0;
    parent = new Node();
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        addTelephone(telephone);
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // The number of elements (referencing a number) stored in the structure.
    cout << counter << endl;
    
    return 0;
}
