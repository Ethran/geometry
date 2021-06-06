#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <bits/stdc++.h>
class Vector;
class Position
{
public:
    Position(int _a, int _b);
    bool operator==(const Position& B);
    int x();
    int y();
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
    Vector();
};
#endif