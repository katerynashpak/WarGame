/**
 * @file Player.cpp
**/

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;



//Output the player's name
ostream& operator <<(std::ostream& out, const Player& p){

    out << p.name;

    return out;
}