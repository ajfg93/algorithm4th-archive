#pragma once
#include <string>
#include <stdexcept>
namespace ythlearn{
    enum Suit{
        spade,
        heart,
        diamond,
        club,
    };

    class Card{
        public:
            Card(){

            }
            Card(std::string card_char, Suit suit):card_character(card_char), s(suit){}
         
            std::string getCardString(){
                return getColor() + " " + getCharacter();
            }
            
        private:
            std::string card_character;
            Suit s;

            std::string getColor(){
                std::string re_str = "";
                switch(s){
                    case spade:
                        re_str = "♠"; break;
                    case heart:
                        re_str = "♥"; break;
                    case diamond:
                        re_str = "♦"; break;
                    case club:
                        re_str = "♣"; break;
                    default:
                        throw std::runtime_error("Suit color wrong");
                }
                return re_str;
            }

            std::string getCharacter(){
                return card_character;
            }
    };
};