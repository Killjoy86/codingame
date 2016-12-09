#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

enum Cards { J = 11, Q, K, A };
enum Suit { D, H, C, S };

class Card {
public:
    Suit suit;
    int value;
};

class Game {
public:
    Game();
    ~Game();

    bool isGameOver();
    void fight();
    void war();
    void addCardToPlayer(int numPlayer, string strCard);
    Card* strToCard(string cardStr);
    Card* getCard(queue<Card*>* player);
    void picksUpCards(queue<Card*>* player);
    string answer();
    void playStage();
private:
    int stage;
    bool isPat;
    queue<Card*>* player1;
    queue<Card*>* player2;
    queue<Card*>* heap1;
    queue<Card*>* heap2;
};

Game::Game() {
    this->stage = 0;
    this->isPat = false;
    this->player1 = new queue<Card*>();
    this->player2 = new queue<Card*>();
    this->heap1 = new queue<Card*>();
    this->heap2 = new queue<Card*>();
}
Game::~Game() {
    delete this->player1;
    delete this->player2;
    delete this->heap1;
    delete this->heap2;
}
bool Game::isGameOver() {
    if ( player1->empty() ) {
        return this->player1->empty();
    } else {
        return this->player2->empty();
    }
}
void Game::fight() {
    Card *card1 = this->getCard(this->player1);
    Card *card2 = this->getCard(this->player2);

    cerr << "Fight: " << card1->value << ' ' << card2->value << endl;

    if ( card1->value > card2->value ) {
        this->picksUpCards(this->player1);
    } else if ( card1->value < card2->value ) {
        this->picksUpCards(this->player2);
    } else {
        this->war();
    }
}
void Game::war() {
    cerr << "war" << endl;
    if ( this->player1->size() < 3 || this->player2->size() < 3 ) {
        isPat = true;
        return;
    }

    for ( int i = 0; i < 3; i++ ) {
        this->getCard(player1);
    }
    for ( int i = 0; i < 3; i++ ) {
        this->getCard(player2);
    }
    this->fight();
}

Card* Game::strToCard(string cardStr) {
    Card *card = new Card();
    for ( int i = 0; i < cardStr.size(); i++ ) {
        if ( cardStr[i] == '1' ) {
            continue;
        }
        switch(cardStr[i]) {
            case 'D':
                card->suit = D;
                break;
            case 'H':
                card->suit = H;
                break;
            case 'C':
                card->suit = C;
                break;
            case 'S':
                card->suit = S;
                break;

            case 'J':
                card->value = J;
                break;
            case 'Q':
                card->value = Q;
                break;
            case 'K':
                card->value = K;
                break;
            case 'A':
                card->value = A;
                break;
            case '0':
                card->value = 10;
                break;
            default:
                card->value = cardStr[i] - '0';
                break;
        }
    }
    return card;
}

Card* Game::getCard(queue<Card*>* player) {
    Card *card = player->front();
    queue<Card*>* heap;
    if ( player == this->player1 ) {
        heap = heap1;
    } else {
        heap = heap2;
    }
    heap->push(card);
    player->pop();

    return card;
}

void Game::picksUpCards(queue<Card*>* player) {
    queue<Card*>* heap = this->heap1;
    while( !heap->empty() ) {
        player->push(heap->front());
        heap->pop();
    }

    heap = this->heap2;
    while( !heap->empty() ) {
        player->push(heap->front());
        heap->pop();
    }
}

void Game::addCardToPlayer(int numPlayer, string strCard) {
    if ( numPlayer == 1 ) {
        this->player1->push(strToCard(strCard));
    } else if ( numPlayer == 2 ) {
        this->player2->push(strToCard(strCard));
    }
}

string Game::answer() {
    if ( this->isPat ) {
        return "PAT";
    }
    if ( this->player1->empty() ) {
        return to_string(2) + " " + to_string(stage);
    } else {
        return to_string(1) + " " + to_string(stage);
    }
}

void Game::playStage() {
    this->stage++;
    this->fight();
}

int main() {
    Game *game = new Game();
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string cardp1; // the n cards of player 1
        cin >> cardp1; cin.ignore();
        game->addCardToPlayer(1, cardp1);
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp2; // the m cards of player 2
        cin >> cardp2; cin.ignore();
        game->addCardToPlayer(2, cardp2);
    }

    while( !game->isGameOver() ) {
        game->playStage();
    }
    cout << game->answer() << endl;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    delete game;
    
    return 0;
}
