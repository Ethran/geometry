#include <cassert>

#include "geometry.h"


int
main()

{
 Position const p(1, 2);
    assert(p.reflection() == Position(2, 1));

    Position pos1(13, 14);
    Rectangle r(10, 2, pos1);
    assert(r.area() == 20);

    Vector v(1, 2);
    Position pos2(14, 16);
    assert(Vector(v) + Position(pos1) == pos2);
    assert(Position(pos1) + Vector(v) == pos2);
    Rectangle r2(10, 2, Position(pos2));
    assert(Rectangle(r) + Vector(v) == r2);
    assert(Vector(v) + Rectangle(r) == r2);
    Rectangles recs({r});
    Rectangles recs2({r2});
    assert(Rectangles(recs) + Vector(v) == recs2);
    assert(Vector(v) + Rectangles(recs) == recs2);

    Position(pos1) += Vector(v);
    Rectangle(r) += Vector(v);
    Rectangles(recs) += Vector(v);
    (Rectangles(recs) += Vector(v)) += Vector(v);
}