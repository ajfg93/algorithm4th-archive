#include <iostream>
#include <string>
#include <sstream>
#include "algorithm-bookeeping/resizing_array_queue.h"
#include "exercises/Card.h"
using namespace std;
using namespace ythlearn;


RandomQueue<Card>& MakeDeck(RandomQueue<Card>& rq_card){
    istringstream is("A 2 3 4 5 6 7 8 9 10 J Q K");
    string s;
    int i = 0;
    while(is >> s){
        for(int Suit_Int = Suit::spade; Suit_Int <= Suit::club; Suit_Int++){
            Suit card_s = static_cast<Suit>(Suit_Int);
            rq_card.enqueue(Card(s, card_s));
            i++;
        }
    }
    return rq_card;
}

void Fapai(RandomQueue<Card>& rq_card){
    int i = 0;
    int j = 1;
    cout << "Player 1:" << endl;
    while(!rq_card.isEmpty()){
        cout << rq_card.dequeue().getCardString() << "|";
        i++;
        if(i % 13 == 0 && j <= 3){
            j++;
            cout << endl;
            cout << "Player " << j << ":" << endl;
        }
    } 
    cout << endl;
   
}


int main(int argc, char *argv[]){   
    RandomQueue<Card> rq;
    MakeDeck(rq);
    // Fapai(rq);
    for(auto s : rq){
        cout << s.getCardString();
    }
    cout << endl;
    return 0;
}