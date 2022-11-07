/**
 * @brief main
 * 
 */
#include <cstdlib>
#include <iostream>
#include <assert.h>
#include <stdexcept>
#include "Card.h"
#include "ComputerPlayer.h"
#include "Card.h"
#include "Player.h"
#include "Deck.h"
#include "TerminalPlayer.h"


using namespace std;

int main(int argc, const char * argv[])
{
    cout << "--------War Game---------\n" << endl;

    Card joker;
    Deck deck;
    deck.shuffle();

    //two players
    //ComputerPlayer p1("Jess (p1)");
    //ComputerPlayer p2("Nick (p2)");

    TerminalPlayer p1("Jess (p1)");
    ComputerPlayer p2("Computer (p2)");

    //each player gets 3 cards (hand)
    p1.receiveCard(deck.draw());
    p2.receiveCard(deck.draw());
    p1.receiveCard(deck.draw());
    p2.receiveCard(deck.draw());
    p1.receiveCard(deck.draw());
    p2.receiveCard(deck.draw());

    srand(time(NULL));

    bool p1First = rand() % 2;

    Card p1Card;
    Card p2Card;

    while(p1.hasCards()){

        if(p1First){    //if p1 goes first
            p1Card = p1.playCard(joker);   //p1 has a joker card
            p2Card = p2.playCard(p1Card);
        }
        else{
            p2Card = p2.playCard(joker);   //p2 has a joker card
            p1Card = p1.playCard(p2Card);
        }

        // check two cards to see who wins
        if(p1Card == p2Card){
            // update the score
            p1.addScore(1);
            p2.addScore(1);

            //cout << p1 << "'s card was " << p1Card;
            //cout << p2 << "'s card was " << p2Card << endl;
            p1.playedCards(p1Card, p2Card); //if we were allowed to make changes to Player.h file

            cout << "It's a tie!"<< endl;
        }
        else if(p2Card < p1Card){
            // update the score
            p1.addScore(2);

            //cout << p1 << "'s card was " << p1Card;
            //cout << p2 << "'s card was " << p2Card << endl;
            p1.playedCards(p1Card, p2Card);

            cout << p1 << " wins the round!"<< endl;
            // based on the winner, determine who goes first for the next round
            p1First = true;
        }
        else{
            // update the score

            p2.addScore(2);
            //cout << p1 << "'s card was " << p1Card;
            //cout << p2 << "'s card was " << p2Card << endl;
            p1.playedCards(p1Card, p2Card);

            cout << p2 << " wins the round!" << endl;
            // based on the winner, determine who goes first for the next round
            p1First = false;
            
        }
        // output the score
        cout << "\n--------------------------------" << endl;
        cout << p1 <<"'s Score: " << p1.getScore() << endl;
        cout << p2 <<"'s Score: " << p2.getScore() << endl;
        cout << "--------------------------------" << endl;

        
        
        

        //if there are cards left in the deck draw cards for the players
        if(!(deck.isEmpty())){
            p1.receiveCard(deck.draw());
            p2.receiveCard(deck.draw());
        }else{
            break;
        }

    }

    //see who won and end the game.
    if(p1.getScore() == p2.getScore()){

        cout << "It's a tie (no winner)!"<< endl;
            
    }
    if(p2.getScore() < p1.getScore()){
        cout << p1 << " wins the game!"<< endl;
    }
    else{
        cout << p2 << " wins the game!" << endl;
    }


    cout << "\n-----Thank you for playing!-----\n"<< endl;
    p1.resetScore();
    p2.resetScore();


    return 0;
}