#include "player.h"

Position::Position()
{
    //TODO
}


Position::Position(int x, int y)
{
    Position::x = x;
    Position::y = y;
}

Player::Player()
{   

}

void Player::initialisePlayer(Position* position, Direction direction)
{
    
    Player::position.x = position->x;
    Player::position.y = position->y;
    Player::direction = direction;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO

    return this->position;
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection()
{
    //TODO
}
