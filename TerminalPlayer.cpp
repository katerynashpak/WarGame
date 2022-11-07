/**
 * @file TerminalPlayer.cpp
**/

#include <iostream>
#include <string>
#include "TerminalPlayer.h"
#include "Player.h"

using namespace std;

/**From TerminalPlayer.h:
 protected:

	int score;
	std::string name;
	std::vector<Card> hand;
 */


Card TerminalPlayer::playCard(const Card& opponentCard){

    unsigned int chosenCard;

    //unsigned int num;

    // if the opponentCard is a Joker, we are going 1st. Tell the player they are going first.
    if (opponentCard.isJoker()) {
        cout << "You are going first." << endl;
    }
    //else, we are going 2nd and opponentCard is what our opponent played. Tell the player what the opponent's card was
    else{
        cout << "You are going second. The opponent's card was " << opponentCard << endl;
    }
    //Display the cards in the player's hand
    cout << "Your 3 cards: " << endl;
    for(unsigned int i = 0; i < hand.size(); i++){
        
        cout << i << " -> " << hand[i] ;
    }

    //prompt them to choose a card
    cout << "Choose one of your cards to play: " ;
    //add error checking to make sure that the user entered the correct value
    while(true){

        cin >> chosenCard;
        if((cin) && (chosenCard == 0 || chosenCard == 1 || chosenCard == 2)){
            break;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout<< "Your input is not valid. Try again" << endl;
    }

    //remove that card from the hand and return the card https://www.cplusplus.com/reference/vector/vector/erase/
    Card playerCard = hand[chosenCard];     // new Card obj, put chosen card in it.
    hand.erase(hand.begin()+chosenCard);    //erase the chosen card from the vector hand.
    return playerCard;                      //returning the new object with the chosen card.

}
