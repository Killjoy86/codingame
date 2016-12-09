#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define ALPHABET 26

using namespace std;

bool isMatch(string& LETTERS, string& word) {
    string let(LETTERS);
    string wor(word);
    for ( int i = 0; i < wor.size(); i++ ) {
        int letter = let.find(wor[i]);
        if ( letter == string::npos ) {
            return false;
        }
        let.erase(letter, 1);
    }
    return true;
}

int getScore(vector<int>& score, string& word ) {
    int sum = 0;
    for ( int i = 0; i < word.size(); i++ ) {
        sum += score[word[i]-'a'];
    }
    return sum;
}
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main() {
    int N;
    cin >> N; cin.ignore();
    vector<string> words;
    for (int i = 0; i < N; i++) {
        string W;
        getline(cin, W);
        if ( W.size() <= 7 ) {
            words.push_back(W);
        }
    }
    string LETTERS;
    getline(cin, LETTERS);

    vector<int> score(ALPHABET);

    for ( int i = 0; i < ALPHABET; i++ ) {
        if ( i == ('e'-'a') || i == ('a'-'a') || i == ('i'-'a') || i == ('o'-'a') ||
             i == ('n'-'a') || i == ('r'-'a') || i == ('t'-'a') || i == ('l'-'a') ||
             i == ('s'-'a') || i == ('u'-'a') ) {
            score[i] = 1;
        }
        if ( i == ('d'-'a') || i == ('g'-'a') ) {
            score[i] = 2;
        }
        if ( i == ('b'-'a') || i == ('c'-'a') || i == ('m'-'a') || i == ('p'-'a') ) {
            score[i] = 3;
        }
        if ( i == ('f'-'a') || i == ('h'-'a') || i == ('v'-'a') || i == ('w'-'a') ||
             i == ('y'-'a') ) {
            score[i] = 4;
        }
        if ( i == ('k'-'a') ) {
            score[i] = 5;
        }
        if ( i == ('j'-'a') || i == ('x'-'a') ) {
            score[i] = 8;
        }
        if ( i == ('q'-'a') || i == ('z'-'a') ) {
            score[i] = 10;
        }
    }

    int max = getScore(score, LETTERS);

    int trueIndex = 0;
    int amount = 0;
    for ( int i = 0; (i < words.size()) && (amount < max); i++ ) {
        if ( isMatch(LETTERS, words[i]) ) {
            int tmp = getScore(score, words[i]);
            if ( tmp > amount ) {
                trueIndex = i;
                amount = tmp;
            }
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << words[trueIndex] << endl;

    return 0;
}
