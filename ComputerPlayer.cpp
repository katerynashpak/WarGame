/**
 * @file ComputerPlayer.cpp
**/

#include <iostream>
#include <string>
#include <vector>
#include "TerminalPlayer.h"
#include "ComputerPlayer.h"
#include "Player.h"

using namespace std;


Card ComputerPlayer::playCard(const Card& opponentCard){
    
    unsigned index = rand() % hand.size();  //index = random num % 3
    Card chosenCard = hand[index];  //store the card at the index in Card object
    hand.erase(hand.begin() + index);   //erase the card from the hand vector
    return chosenCard;

}
