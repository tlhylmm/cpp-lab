#include <iostream>
using namespace std;
#pragma once


class Player {
    
    protected:
        int age;
        string name;
    public:
        enum Direction {
            EAST,
            NORTH,
            NORTH_EAST,
            NORTH_WEST,
            SOUTH,
            SOUTH_EAST,
            SOUTH_WEST,
            WEST,
        };
        int getAge();
        const string& getName();
        void Move(Direction direction);
        Player(){};
        Player(const string& name, int age); 
        ~Player(){};
    private:
        void MoveEast();
        void MoveNorth();
        void MoveNorthEast();
        void MoveNorthWest();
        void MoveSouth();
        void MoveSouthEast();
        void MoveSouthWest();
        void MoveWest();
};