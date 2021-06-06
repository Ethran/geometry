#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <bits/stdc++.h>
class Vector;
class Position
{
public:
    Position(int _a, int _b);
    bool operator==(const Position& B);
    int x() const;
    int y() const;
    Position reflection();
    Position& operator+=(const Vector& B);
    static const Position& origin()
    {
	static const Position objectOrigin(0, 0);
	return objectOrigin;
    }

private:
    int xPos, yPos;
};
class Vector
{
public:
    Vector(int _a, int _b);
    bool operator==(const Vector& B);
    int x() const;
    int y() const;
    Vector reflection();
    Vector& operator+=(const Vector& B);

private:
    int xVec, yVec;
};
class Rectangle
{
public:
private:
}
#endif