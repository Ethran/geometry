#include "geometry.h"

///**Point **///



Point::Point(const int &_a, const int &_b)
  : xPos(_a)
  , yPos(_b)
{}



bool
Point::operator==(const Point &B) const
{
  if (this->xPos == B.xPos && this->yPos == B.yPos)
    return true;
  return false;
}



Point &
Point::operator+=(const Point &B)
{
  this->xPos += B.x();
  this->yPos += B.y();

  return *this;
}



Point
Point::operator+(const Point &B) const
{
  Point result = *this;
  result += B;
  return result;
}



const int &
Point::x() const
{
  return xPos;
}



const int &
Point::y() const
{
  return yPos;
}



///** Position**///



Position
Position::reflection() const
{
  return Position(yPos, xPos);
}



Position &
Position::operator=(const Position &B)
{
  static_cast<Point &>(*this) = B;
  return *this;
}
Position &
Position::operator+=(const Vector &B)
{
  static_cast<Point &>(*this) += B;
  return *this;
}



Position
Position::operator+(const Vector &B) const
{
  Position result = *this;
  result += B;
  return result;
}



Position::operator Vector() const
{
  return Vector(x(), y());
}


///** Vector**///



Vector
Vector::reflection() const
{
  return Vector(yPos, xPos);
}



Vector &
Vector::operator=(const Vector &B)
{
  static_cast<Point &>(*this) = B;
  return *this;
}



Vector &
Vector::operator+=(const Vector &B)
{
  static_cast<Point &>(*this) += B;
  return *this;
}



Vector
Vector::operator+(const Vector &B) const
{
  Vector result = *this;
  result += B;
  return result;
}



Position
Vector::operator+(const Position &B) const
{
  Position result = B;
  result += *this;
  return result;
}



Rectangle
Vector::operator+(const Rectangle &B) const
{
  Rectangle result(B);
  result += *this;
  return result;
}



Rectangles
Vector::operator+(const Rectangles &B) const
{
  Rectangles result = B;
  result += *this;
  return result;
}



Vector::operator Position() const
{
  return Position(x(), y());
}


///** Rectangle**///



Rectangle::Rectangle(const int &     _width,
                     const int &     _height,
                     const Position &_pos)
  : widthRec(_width)
  , heightRec(_height)
  , posRec(_pos)
{
  assert(_width > 0);
  assert(_height > 0);
}



bool
Rectangle::operator==(const Rectangle &B) const
{
  if (this->widthRec == B.widthRec && this->heightRec == B.heightRec &&
      this->posRec == B.posRec)
    return true;
  return false;
}



bool
Rectangle::operator!=(const Rectangle &B) const
{
  if (*this == B)
    return false;
  return true;
}



Rectangle &
Rectangle::operator+=(const Vector &B)
{
  posRec += B;
  return *this;
}



Rectangle &
Rectangle::operator=(const Rectangle &B)
{
  if (this != &B)
    {
      posRec    = B.pos();
      widthRec  = B.width();
      heightRec = B.height();
    }
  return *this;
}



Rectangle
Rectangle::operator+(const Vector &B) const
{
  Rectangle result = *this;
  result += B;
  return result;
}



const unsigned int &
Rectangle::width() const
{
  return widthRec;
}



const unsigned int &
Rectangle::height() const
{
  return heightRec;
}



const Position &
Rectangle::pos() const
{
  return posRec;
}



Rectangle
Rectangle::reflection() const
{
  return Rectangle(heightRec, widthRec, posRec.reflection());
}



int
Rectangle::area() const
{
  return widthRec * heightRec;
}



///*** Rectangles  **///


 unsigned  int
Rectangles::size() const
{
  return colection.size();
}


Rectangle &
Rectangles::operator[](unsigned const int index)
{
  assert(index < size());
  return colection[index];
}



const Rectangle &
Rectangles::operator[](unsigned const int index) const
{
  assert(index < size());
  return colection[index];
}



bool
Rectangles::operator==(const Rectangles &B) const
{
  if (this->size() != B.size())
    return false;
  for (unsigned int i = 0; i < this->size(); ++i)
    {
      if (colection[i] != B[i])
        return false;
    }
  return true;
}



Rectangles &
Rectangles::operator+=(const Vector &B)
{
  for (auto &it : colection)
    {
      it += B;
    }
  return *this;
}

Rectangles &
Rectangles::operator=(const Rectangles &B)
{
  if (this != &B)
    {
      colection = B.colection;
    }
  return *this;
}

Rectangles &
Rectangles::operator=(Rectangles &&B)
{
  if (this != &B)
    colection = move(B.colection);
  return *this;
}

Rectangles
Rectangles::operator+(const Vector &B) const
{
  Rectangles result = *this;
  result += B;
  return result;
}



///*** functions dopelniajace Rectangles ***///



Rectangles
operator+(const Rectangles &&a, const Vector &b)
{
  Rectangles result(std::move(a));
  result += b;
  return result;
}


Rectangles
operator+(const Vector &b, const Rectangles &&a)
{
  Rectangles result = std::move(a);
  result += b;
  return result;
}



///***reszta functions ***///

Rectangle
merge_horizontally(const Rectangle &rect1, const Rectangle &rect2)
{
  assert(check_horizontally(rect1, rect2));
  return Rectangle(rect1.width(), rect1.height() + rect2.height(), rect1.pos());
}


// check if marge is posible
bool
check_horizontally(const Rectangle &rect1, const Rectangle &rect2)
{
  if (static_cast<int>(rect1.height()) + rect1.pos().y() != rect2.pos().y())
    return false;
  if (rect1.width() != rect2.width())
    return false;
  if (rect1.pos().x() != rect2.pos().x())
    return false;
  return true;
}


// check if marge is posible

Rectangle
merge_vertically(const Rectangle &rect1, const Rectangle &rect2)
{
  assert(check_vertically(rect1, rect2));

  return Rectangle(rect1.width() + rect2.width(), rect1.height(), rect1.pos());
}



bool
check_vertically(const Rectangle &rect1, const Rectangle &rect2)
{
  if (static_cast<int>(rect1.width()) + rect1.pos().x() != rect2.pos().x())
    return false;
  if (rect1.height() != rect2.height())
    return false;
  if (rect1.pos().y() != rect2.pos().y())
    return false;
  return true;
}



Rectangle
merge_all(const Rectangles &A)
{
  assert(A.size());
  Rectangle merged = A[0];
  for (unsigned int i = 1; i < A.size(); ++i)
    {
      if (check_horizontally(merged, A[i]))
        merged = merge_horizontally(merged, A[i]);
      else if (check_vertically(merged, A[i]))
        merged = merge_vertically(merged, A[i]);
      else
        assert(false);
    }
  return merged;
}