#include <cassert>

#include "geometry.h"


int
main()

{
   Position p(13, 14);
    Rectangle r(10, 2, p);
    Rectangles recs1({r, r});
    auto adr = &(recs1[0]);
    auto recs2 = std::move(recs1) + Vector(1, 1);
    assert(&(recs2[0]) == adr);
    auto recs3 = Vector(1, 1) + std::move(recs2);
    assert(&(recs3[0]) == adr);

}