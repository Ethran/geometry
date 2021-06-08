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
    Point(const int& _a, const int& _b);
    Point() = delete;
    bool operator==(const Point& B) const;
    const int& x() const;
    const int& y() const;

protected:
    int xPos, yPos;
};

class Position : public Point
{
public:
    Position(int _a, int _b)
        : Point(_a, _b)
    {
    }
    Position() = delete;
    // bool& operator+=(const Position& B) const;
    Position& operator+=(const Vector& B);
    Position reflection() const;
    static const Position& origin()
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
    {
    }
    Vector() = delete;
    Vector reflection() const;

    Vector& operator+=(const Vector& B);

private:
};

class Rectangle
{
public:
    Rectangle(const unsigned int& _width, const unsigned int& _height, const Position& _pos);
    Rectangle(const unsigned int& _width, const unsigned int& _height);
    Rectangle() = delete;
    bool operator==(const Rectangle& B) const;
    bool operator!=(const Rectangle& B) const;

    const unsigned int& width() const;
    const unsigned int& height() const;
    const Position& pos() const;
    Rectangle reflection() const;
    Rectangle& operator+=(const Vector& B);
    int area() const;

private:
    unsigned int widthRec;
    unsigned int heightRec;
    Position posRec;
};

class Rectangles
{
public:
    Rectangles(std::initializer_list<Rectangle> _colection)
        : colection(_colection)
    {
    }
    Rectangles()
    {
    }

    unsigned const int size() const;
    Rectangle& operator[](unsigned const int index);
    const Rectangle& operator[](unsigned const int index) const;

    bool operator==(const Rectangles& B) const;
    Rectangles& operator+=(const Vector& B);

private:
    std::vector<Rectangle> colection;
};

Rectangle merge_horizontally(const Rectangle& rect1, const Rectangle& rect2);
bool check_horizontally(const Rectangle& rect1, const Rectangle& rect2);

Rectangle merge_vertically(const Rectangle& rect1, const Rectangle& rect2);
bool check_vertically(const Rectangle& rect1, const Rectangle& rect2);

Rectangles merge_all(const Rectangles& A);

#endif