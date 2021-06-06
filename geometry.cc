#include "geometry.h"

Position::Position(int _a, int _b)
    : xPos(_a)
    , yPos(_b)
{
}

bool Position::operator==(const Position& B)
{
    if(this->xPos == B.xPos && this->yPos == B.yPos) {
	std::cout << " tak ";
	return true;
    }
    std::cout << " nie ";
    return false;
}

int Position::x()
{
    return xPos;
}

int Position::y()
{
    return yPos;
}

Position Position::reflection()
{
    return Position(yPos, xPos);
}
Position& Position::operator+=(const Vector& B)
{
}

// static const Position& Position::origin()
//{
//    static const Position objectOrigin(0, 0);
//    return objectOrigin;
//}
