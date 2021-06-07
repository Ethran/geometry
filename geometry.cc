#include "geometry.h"

Point::Point(int _a, int _b)
    : xPos(_a)
    , yPos(_b)
{
}

bool Point::operator==(const Point& B)
{
    if(this->xPos == B.xPos && this->yPos == B.yPos) {
	std::cout << " tak ";
	return true;
    }
    std::cout << " nie ";
    return false;
}

const int& Point::x() const
{
    return xPos;
}

const int& Point::y() const
{
    return yPos;
}

Point Point::reflection()
{
    return Point(yPos, xPos);
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

Vector& Vector::operator+=(const Vector& B)
{
    this->xVec += B.x();
    this->yVec += B.y();
    return *this;
}