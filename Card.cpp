/**
 * @file Card.cpp
 * 
**/

#include "Card.h"
#include <iostream>

using namespace std;

/**
    * @brief Construct a new Card object. The empty constructor will create a joker card.
    * The joker card is a special card given to the player going first.
**/
Card::Card(){
    cardRank = Joker;
    cardSuit = Spades; //otherwise an unknown value will be assigned
}


/**From Card.h: 
private:
	Suit cardSuit;
	Rank cardRank;
**/
Card::Card(Suit suit, Rank rank){
    cardSuit = suit;
    cardRank = rank;
}

/**
    * @brief Output the card to an output stream as "rank of suit", except for the joker which 
    * is just output as "Joker"
    * 
    * @return std::ostream& 
    */
ostream& operator <<(std::ostream &os, const Card &card){

    if(card.isJoker()){     
        os << rankNames[card.cardRank] << endl;
    }
    else{
        os << rankNames[card.cardRank] << " of " << suitNames[card.cardSuit] << endl;
    }
    
    return os;
}

/**
    * @brief == compare operator. For the game of war we only care about the rank value
    * 
    * @param lhs 
    * @param rhs 
    * @return true 
    * @return false 
    */
bool operator ==(const Card &lhs, const Card &rhs){ 
    
    return lhs.cardRank == rhs.cardRank;

}

/**
    * @brief < compare operator. For the game of war we only care about the rank value
    * 
    * @param lhs 
    * @param rhs 
    * @return true 
    * @return false 
    */
bool operator <(const Card &lhs, const Card &rhs){

    return lhs.cardRank < rhs.cardRank;

}

