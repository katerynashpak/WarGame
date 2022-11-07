/**
 * @file Deck.cpp
 * 
 */
 #include <iostream>
 #include "Deck.h"
 #include "Card.h"
 #include <algorithm>    // std::shuffle
 #include <stdexcept>    
 #include <chrono>       // std::chrono::system_clock  
 #include <random>       // default_random_engine
 #include <vector>

using namespace std;

/**private:
	Suit cardSuit;
	Rank cardRank;
**/
//4 suits
//13 ranks


Deck::Deck(){
    //for loop for the Card suit
    for(unsigned int intSuit = 0; intSuit < 4; intSuit++){
        //for loop for the Card rank
        for(unsigned int intRank = 1; intRank < 14; intRank++){

            //instatiate a Card(suit, rank)
            //Card(Card::Suit(intSuit), Card::Rank(intRank));
            //add this new Card to the Deck vector
            cardDeck.push_back(Card(Card::Suit(intSuit), Card::Rank(intRank)));
        }
    
    }
    nextCard = 0;
}

Card Deck::draw(){
    //check the nextCard > max cards (52)
    //if it is, throw the out of range exception
    if(nextCard >= MaxCards){
        throw out_of_range("Max number of cards in the deck is 52.");
    }
    //else, get the nextCard from the vector
    //increment nextCard
    else{
        //return the Card we fetched
        return cardDeck[nextCard++];
    }
}

/**
 * @brief Return true if the deck is empty (next available card is past the end of the deck)
 * 
 * @return true 
 * @return false 
 */
bool Deck::isEmpty() const{
    return nextCard >= MaxCards; //from Deck.h:  #define MaxCards 52
}


void Deck::shuffle(){
     //https://www.cplusplus.com/reference/algorithm/shuffle/

    //obtain a time-based seed
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(Deck::cardDeck.begin(), Deck::cardDeck.end(), default_random_engine(seed));
    nextCard = 0;


}

