#include "Player.h"

int Player::getAge()
{
    return this->age;
}

const string& Player::getName()
{
    return this->name;
}

void Player::Move(Direction direction)
{
    cout << "'" << this->name << "' is moving to ";
    switch (direction){
        case EAST:
            MoveEast();
            break;
        case NORTH:
            MoveNorth();
            break;
        case NORTH_EAST:
            MoveNorthEast();
            break;
        case NORTH_WEST:
            MoveNorthWest();
            break;
        case SOUTH:
            MoveSouth();
            break;  
        case SOUTH_EAST:
            MoveSouthEast();
            break;
        case SOUTH_WEST:
            MoveSouthWest();
            break;
        case WEST:
            MoveWest();
            break;
    }  
}

Player::Player(const string& name, int age = 0)
{
    this->name = name;
    this->age = age;
}

void Player::MoveEast()
{
    cout << "East" << endl;
}

void Player::MoveNorth()
{
    cout << "North" << endl;
}

void Player::MoveNorthEast()
{
    cout << "NorthEast" << endl;
}

void Player::MoveNorthWest()
{
    cout << "NorthWest" << endl;
}

void Player::MoveSouth()
{
    cout << "South" << endl;
}

void Player::MoveSouthEast()
{
    cout << "SouthEast" << endl;
}

void Player::MoveSouthWest()
{
    cout << "SouthWest" << endl;
}

void Player::MoveWest()
{
    cout << "West" << endl;
}
