#include <cassert>

#include "geometry.h"


int
main()

{
    Position p(1, 2);
    assert(p.reflection() == Position(2, 1));

    Position pos1(13, 14);
    Rectangle r(10, 2, pos1);
    assert(r.area() == 20);

    Vector v(1, 2);
    assert(v.reflection() == Vector(2, 1));
    Position pos2(14, 16);
    assert(v + pos1 == pos2);
    assert(pos1 + v == pos2);
    Rectangle r2(10, 2, pos2);
    assert(r + v == r2);
    assert(v + r == r2);
    Rectangles recs({r});
    Rectangles recsd;
    Rectangles recs2({r2});
    assert(recs + v == recs2);
    assert(v + recs == recs2);
    assert(v + v == Vector(2, 4));

    pos1 += v;
    assert(pos1 == pos2);

    r += v;
    assert(r == r2);

    recs += v;
    assert(recs == recs2);

    (recs += v) += v;
}