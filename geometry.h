#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <bits/stdc++.h>
class Point;
class Position;
class Vector;
class Rectangle;
class Rectangles;

class Point
{
public:
  Point(const int &_a, const int &_b);
  Point(const Point &_a);
  Point() = delete;
  bool
  operator==(const Point &B) const;

  Point &
  operator+=(const Point &B);
  Point
  operator+(const Point &B) const;

  const int &
  x() const;
  const int &
  y() const;

protected:
  int xPos, yPos;
};

class Position : public Point
{
public:
  Position(int _a, int _b)
    : Point(_a, _b)
  {}
  Position(Vector _a);
  Position() = delete;
  // bool& operator+=(const Position& B) const;
  Position &
  operator=(const Position &B);
  Position &
  operator+=(const Vector &B);
  Position
  operator+(const Vector &B) const;


  // explicit operator Vector() const;

  Position
  reflection() const;

  static const Position &
  origin()
  {
    static const Position objectOrigin(0, 0);
    return objectOrigin;
  }
};

class Vector : public Point
{
public:
  Vector(int _a, int _b)
    : Point(_a, _b)
  {}
  Vector() = delete;
  Vector
  reflection() const;
  Vector &
  operator=(const Vector &B);
  Vector &
  operator+=(const Vector &B);
  Vector
  operator+(const Vector &B) const;
  Position
  operator+(const Position &B) const;
  Rectangle
  operator+(const Rectangle &B) const;
  Rectangles
  operator+(const Rectangles &B) const;
  //  explicit operator Position() const;

private:
};

class Rectangle
{
public:
  Rectangle(const int &     _width,
            const int &     _height,
            const Position &_pos = Position::origin());
  Rectangle() = delete;
  bool
  operator==(const Rectangle &B) const;
  bool
  operator!=(const Rectangle &B) const;
  Rectangle &
  operator+=(const Vector &B);
  Rectangle &
  operator=(const Rectangle &B);
  Rectangle
  operator+(const Vector &B) const;

  const unsigned int &
  width() const;
  const unsigned int &
  height() const;
  const Position &
  pos() const;
  Rectangle
  reflection() const;

  int
  area() const;

private:
  unsigned int widthRec;
  unsigned int heightRec;
  Position     posRec;
};

class Rectangles
{
public:
  Rectangles(std::initializer_list<Rectangle> _colection)
    : colection(_colection)
  {}
  Rectangles()
  {}

  unsigned const int
  size() const;
  Rectangle &
  operator[](unsigned const int index);
  const Rectangle &
  operator[](unsigned const int index) const;

  bool
  operator==(const Rectangles &B) const;
  Rectangles &
  operator=(const Rectangles &B);
  Rectangles &
  operator+=(const Vector &B);
  Rectangles
  operator+(const Vector &B) const;

private:
  std::vector<Rectangle> colection;
};

Rectangle
merge_horizontally(const Rectangle &rect1, const Rectangle &rect2);
bool
check_horizontally(const Rectangle &rect1, const Rectangle &rect2);

Rectangle
merge_vertically(const Rectangle &rect1, const Rectangle &rect2);
bool
check_vertically(const Rectangle &rect1, const Rectangle &rect2);

Rectangles
merge_all(const Rectangles &A);

#endif