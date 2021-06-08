#include "geometry.h"

Point::Point(const int& _a, const int& _b)
    : xPos(_a)
    , yPos(_b)
{
}

bool Point::operator==(const Point& B) const
{
    if(this->xPos == B.xPos && this->yPos == B.yPos)
	return true;
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

Position Position::reflection() const
{
    return Position(yPos, xPos);
}
Position& Position::operator+=(const Vector& B)
{
    this->xPos += B.x();
    this->yPos += B.y();
    return *this;
}

Vector Vector::reflection() const
{
    return Vector(yPos, xPos);
}

Vector& Vector::operator+=(const Vector& B)
{
    this->xPos += B.x();
    this->yPos += B.y();
    return *this;
}

Rectangle::Rectangle(const int& _width, const int& _height, const Position& _pos)
    : widthRec(_width)
    , heightRec(_height)
    , posRec(_pos)
{
}
Rectangle::Rectangle(const int& _width, const int& _height)
    : widthRec(_width)
    , heightRec(_height)
    , posRec(Position::origin())
{
}
bool Rectangle::operator==(const Rectangle& B) const
{
    if(this->widthRec == B.widthRec && this->heightRec == B.heightRec && this->posRec == B.posRec)
	return true;
    return false;
}
bool Rectangle::operator!=(const Rectangle& B) const
{
    if(this->widthRec == B.widthRec && this->heightRec == B.heightRec && this->posRec == B.posRec)
	return false;
    return true;
}
const unsigned int& Rectangle::width() const
{
    return widthRec;
}

const unsigned int& Rectangle::height() const
{
    return heightRec;
}

const Position& Rectangle::pos() const
{
    return posRec;
}

Rectangle Rectangle::reflection() const
{
    return Rectangle(heightRec, widthRec, posRec.reflection());
}

Rectangle& Rectangle::operator+=(const Vector& B)
{
    posRec += B;
    return *this;
}

int Rectangle::area() const
{
    return widthRec * heightRec;
}

unsigned const int Rectangles::size() const
{
    return colection.size();
}
Rectangle& Rectangles::operator[](unsigned const int index)
{
    assert(index < size());
    return colection[index];
}
const Rectangle& Rectangles::operator[](unsigned const int index) const
{
    assert(index < size());
    return colection[index];
}

bool Rectangles::operator==(const Rectangles& B) const
{
    if(this->size() != B.size())
	return false;
    for(unsigned int i = 0; i < this->size(); ++i) {
	if(colection[i] != B[i])
	    return false;
    }
    return true;
}
Rectangles& Rectangles::operator+=(const Vector& B)
{
    for(auto& it : colection) {
	it += B;
    }
    return *this;
}

Rectangle merge_horizontally(const Rectangle& rect1, const Rectangle& rect2)
{
    if(!check_horizontally(rect1, rect2))
	exit(EXIT_FAILURE);
    return Rectangle(rect1.height() + rect2.height(), rect1.width(), rect1.pos());
}
bool check_horizontally(const Rectangle& rect1, const Rectangle& rect2)
{
    if(static_cast<int>(rect1.height()) + rect1.pos().y() != rect2.pos().y())
	return false;
    if(rect1.width() == rect2.width())
	return false;
    if(rect1.pos().x() == rect2.pos().x())
	return false;
    return true;
}
Rectangle merge_vertically(const Rectangle& rect1, const Rectangle& rect2)
{
    if(!check_vertically(rect1, rect2))
	exit(EXIT_FAILURE);
    return Rectangle(rect1.height(), rect1.width() + rect2.width(), rect1.pos());
}
bool check_vertically(const Rectangle& rect1, const Rectangle& rect2)
{
    if(static_cast<int>(rect1.width()) + rect1.pos().x() == rect2.pos().x())
	return false;
    if(rect1.height() == rect2.height())
	return false;
    if(rect1.pos().y() == rect2.pos().y())
	return false;
    return true;
}
Rectangles merge_all(const Rectangles& A)
{
    Rectangle merged = A[0];
    for(unsigned int i = 1; i < A.size(); ++i) {
	if(check_horizontally(merged, A[i]))
	    merge_horizontally(merged, A[i]);
	else if(check_vertically(merged, A[i]))
	    merge_vertically(merged, A[i]);
	else
	    exit(EXIT_FAILURE);
    }
    return Rectangles({ merged });
}