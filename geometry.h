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
    Point(int _a, int _b);
    bool operator==(const Point& B);
    const int& x() const;
    const int& y() const;
    Point reflection();

protected:
    int xPos, yPos;
};

class Position : public Point
{
public:
    using Point::Point;
    Position& operator+=(const Vector& B);
    static const Position& origin()
    {
	static const Position objectOrigin(0, 0);
	return objectOrigin;
    }
};

class Vector : public Point
{
public:
    using Point::Point;
    Vector& operator+=(const Vector& B);

private:
    int xVec, yVec;
};



class Rectangle
{
public:
    Rectangle(int _width, int _height, Position _pos);
    Rectangle(int _width, int _height);
    bool operator==(const Rectangle& B);
    Rectangle reflection();
    Rectangle& operator+=(const Vector& B);
    int area();

private:
    unsigned int width;
    unsigned int height;
    Position pos;
};

class Rectangles
{
public:
private:
};
#endif