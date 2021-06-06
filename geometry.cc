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

int Position::x() const
{
    return xPos;
}

int Position::y() const
{
    return yPos;
}

Position Position::reflection()
{
    return Position(yPos, xPos);
}
Position& Position::operator+=(const Vector& B)
{
    this->xPos += B.x();
    this->yPos += B.y();
    return *this;
}

// static const Position& Position::origin()
//{
//    static const Position objectOrigin(0, 0);
//    return objectOrigin;
//}

Vector::Vector(int _a, int _b)
    : xVec(_a)
    , yVec(_b)
{
}

bool Vector::operator==(const Vector& B)
{
    if(this->xVec == B.xVec && this->yVec == B.yVec) {
	std::cout << " tak ";
	return true;
    }
    std::cout << " nie ";
    return false;
}

int Vector::x() const
{
    return xVec;
}

int Vector::y() const
{
    return yVec;
}

Vector Vector::reflection()
{
    return Vector(yVec, xVec);
}
Vector& Vector::operator+=(const Vector& B)
{
    this->xVec += B.x();
    this->yVec += B.y();
    return *this;
}