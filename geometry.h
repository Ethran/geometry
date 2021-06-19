#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <bits/stdc++.h>



class Point;
class Position;
class Vector;
class Rectangle;
class Rectangles;


// klasa bazowa dla position i vector
class Point
{
public:
  Point(const int &_a, const int &_b);

  Point() = delete;

  //
  //  bool
  //  operator==(const Point &B) const;

  Point &
  operator+=(const Point &B);

  Point
  operator+(const Point &B) const;

  [[nodiscard]] const int &
  x() const;

  [[nodiscard]] const int &
  y() const;

  virtual ~Point() = default; // pure  virtual function → abstract class


protected:
  int xPos, yPos;
};

class Position : public Point
{
public:
  Position(int _a, int _b);


  Position()                 = delete;
  Position(const Position &) = default;


  Position &
  operator=(const Position &B);

  bool
  operator==(const Position &B) const;


  Position &
  operator+=(const Vector &B);

  Position
  operator+(const Vector &B) const;

  explicit operator Vector() const;

  Position
  reflection() const;



  [[nodiscard]] static const Position &
  origin()
  {
    static const Position objectOrigin(0, 0);
    return objectOrigin;
  }
};



class Vector : public Point
{
public:
  Vector(int _a, int _b);

  Vector()               = delete;
  Vector(const Vector &) = default;


  [[nodiscard]] Vector
  reflection() const;

  Vector &
  operator=(const Vector &B);

  bool
  operator==(const Vector &B) const;

  Vector &
  operator+=(const Vector &B);

  Vector
  operator+(const Vector &B) const;

  Position
  operator+(const Position &B) const;

  Rectangle
  operator+(const Rectangle &B) const;



  explicit operator Position() const;

private:
};



class Rectangle
{
public:
  Rectangle(const int &     _width,
            const int &     _height,
            const Position &_pos = Position::origin());

  Rectangle()                  = delete;
  Rectangle(const Rectangle &) = default;



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

  [[nodiscard]] const unsigned int &
  width() const;

  [[nodiscard]] const unsigned int &
  height() const;

  [[nodiscard]] const Position &
  pos() const;

  [[nodiscard]] Rectangle
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
  Rectangles(std::initializer_list<Rectangle> _colection);

  Rectangles();

  Rectangles(const Rectangles &B) = default;

  Rectangles(Rectangles &&B) = default;


  [[nodiscard]] unsigned int
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
  operator=(Rectangles &&B) = default;

  Rectangles &
  operator+=(const Vector &B);



private:
  std::vector<Rectangle> colection;
};

// plus kopiujacy
Rectangles
operator+(const Rectangles &a, const Vector &b);


// plus przenoszacy
Rectangles
operator+(Rectangles &&a, const Vector &b);

// to samo tylko na odwrót


// plus kopiujacy
Rectangles
operator+(const Vector &b, const Rectangles &a);


// plus przenoszacy
Rectangles
operator+(const Vector &b, Rectangles &&a);



Rectangle
merge_horizontally(const Rectangle &rect1, const Rectangle &rect2);



bool
check_horizontally(const Rectangle &rect1, const Rectangle &rect2);



Rectangle
merge_vertically(const Rectangle &rect1, const Rectangle &rect2);



bool
check_vertically(const Rectangle &rect1, const Rectangle &rect2);



Rectangle
merge_all(const Rectangles &A);



#endif