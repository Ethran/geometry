#include "geometry.h"
#include <cassert>

// Opis testów
// grupa 1 tworzenie obiektów
// grupa 2 usuniete Position(), Vector() i  Rectangle(), const na origin
// grupa 3 area, +=, +, reflection, move dla Rectangles
// grupa 4 merge_horizontally, merge_vertically
// grupa 5 merge_all
// grupa 6 niekompilujące się operatory

template <typename PosOrVec>
void test_pos_or_vec() {
    PosOrVec p(2, 20);
    PosOrVec const p2(3, -30);
    assert(p.x() == 2 && p.y() == 20);
    assert(p2.x() == 3 && p2.y() == -30);
    p = p2;
    assert(p2 == p);
    assert(p.x() == 3 && p.y() == -30);
    PosOrVec const p3(p);
    assert(p3.x() == 3 && p3.y() == -30);
    assert(p3 == p);
    PosOrVec const p4(std::move(p));
    assert(p4.x() == 3 && p4.y() == -30);
    PosOrVec const p5 = std::move(p4);
    assert(p5.x() == 3 && p5.y() == -30);
}

int main() {
    #if TEST_NUM == 101
    // tworzenie obiektów Position
    test_pos_or_vec<Position>();
    #endif

    #if TEST_NUM == 102
    // tworzenie obiektów Vector
    test_pos_or_vec<Vector>();
    #endif

    #if TEST_NUM == 103
    // testy prostokątów
    Rectangle const r2(1, 2, Position(3, 4));
    assert(r2.width() == 1);
    assert(r2.height() == 2);
    assert(r2.pos().x() == 3);
    assert(r2.pos().y() == 4);

    Rectangle p(2, 20);
    Rectangle const p2(3, 30);
    assert(p.width() == 2 && p.height() == 20);
    assert(p2.width() == 3 && p2.height() == 30);
    p = p2;
    assert(p.width() == 3 && p.height() == 30);
    Rectangle const p3(p);
    assert(p3.width() == 3 && p3.height() == 30);
    assert(p3 == p);
    Rectangle const p4(std::move(p));
    assert(p4.width() == 3 && p4.height() == 30);
    Rectangle const p5 = std::move(p4);
    assert(p5.width() == 3 && p5.height() == 30);
    #endif

    #if TEST_NUM == 104
    // testy Rectangles
    Rectangles rect1({Rectangle(1, 2), Rectangle(3, 4)});
    assert(rect1.size() == static_cast<size_t>(2));
    assert(rect1[0] == Rectangle(1, 2));
    assert(rect1[1] == Rectangle(3, 4));
    Rectangles rect2(rect1);
    assert(rect1 == rect2);
    rect2[0] += Vector(0, 0);

    Rectangles rect3(std::move(rect1));
    assert(rect3 == rect2);
    assert(!(rect3 == rect1));

    Rectangles const rect4 = rect2;
    assert(rect4 == rect2);
    assert(rect2[0] == Rectangle(1, 2));
    assert(rect2[1] == Rectangle(3, 4));
    assert(rect4[0] == Rectangle(1, 2));
    assert(rect4[1] == Rectangle(3, 4));
    assert(rect4.size() == rect2.size());

    Rectangles rect5 = std::move(rect2);
    assert(rect5 == rect4);
    assert(!(rect5 == rect2));
    #endif

    // W następnych 6 testach są niedodatnie wymiary.
    #if TEST_NUM == 105
    Rectangle p(0, 1);
    #endif

    #if TEST_NUM == 106
    Rectangle p(1, 0);
    #endif

    #if TEST_NUM == 107
    Rectangle p(0, 1, Position(1, 1));
    #endif

    #if TEST_NUM == 108
    Rectangle p(1, 0, Position(1, 1));
    #endif

    #if TEST_NUM == 109
    Rectangle p(-1, 1, Position(1, 1));
    #endif

    #if TEST_NUM == 110
    Rectangle p(1, -1, Position(1, 1));
    #endif

    #if TEST_NUM == 201
    // poprawne operacje
    Position p1(1, 2);
    Vector v1(p1);
    Vector v2(2, 3);
    Position p2(v2);
    p2 = Position(v1);
    v1 = Vector(p2);
    #endif

    #if TEST_NUM == 202
    assert(Position::origin() == Position(0, 0));
    #endif

    // Kolejne 7 testów powinno się zakończyć błędem wykonania.
    #if TEST_NUM == 203
    Position p1(1, 2);
    Vector v1(p1);
    Vector v2(2, 3);
    Position p2(v2);
    p2 = Position(v1);
    v1 = Vector(p2);
    // niepoprawna operacja: niejawne rzutowanie
    p2 = v1;
    #endif

    #if TEST_NUM == 204
    Position p1(1, 2);
    Vector v1(p1);
    Vector v2(2, 3);
    Position p2(v2);
    p2 = Position(v1);
    v1 = Vector(p2);
    // niepoprawna operacja: niejawne rzutowanie
    v1 = p2;
    #endif

    #if TEST_NUM == 205
    [[maybe_unused]] Position p;
    #endif

    #if TEST_NUM == 206
    [[maybe_unused]] Vector v;
    #endif

    #if TEST_NUM == 207
    [[maybe_unused]] Rectangle rec;
    #endif

    #if TEST_NUM == 208
    [[maybe_unused]] Rectangle rec(3);
    #endif

    #if TEST_NUM == 209
    Position::origin() += Vector(1, 2);
    #endif

    #if TEST_NUM == 301
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
    #endif

    #if TEST_NUM == 302
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
    #endif

    #if TEST_NUM == 303
    Position p(13, 14);
    Rectangle r(10, 2, p);
    Rectangles recs1({r, r});
    auto adr = &(recs1[0]);
    auto recs2 = std::move(recs1) + Vector(1, 1);
    assert(&(recs2[0]) == adr);
    auto recs3 = Vector(1, 1) + std::move(recs2);
    assert(&(recs3[0]) == adr);
    #endif

    #if TEST_NUM == 401
    Position pos1(12, 14);
    Position pos2(16, 14);
    Rectangle r2(4, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 402
    Position pos1(12, 14);
    Position pos2(16, 14);
    Rectangle r2(4, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_horizontally(r2.reflection(), r3.reflection());
    #endif

    // Kolejne 10 testów powinno się zakończyć błędem wykonania.
    #if TEST_NUM == 403
    Position pos1(12, 14);
    Position pos2(16, 14);
    Rectangle r2(3, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 404
    Position pos1(13, 13);
    Position pos2(16, 14);
    Rectangle r2(3, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 405
    Position pos1(13, 14);
    Position pos2(16, 13);
    Rectangle r2(3, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 406
    Position pos1(13, 14);
    Position pos2(15, 14);
    Rectangle r2(3, 20, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 407
    Position pos1(13, 14);
    Position pos2(16, 14);
    Rectangle r2(3, 21, pos1);
    Rectangle r3(7, 20, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 408
    Position pos1(14, 12);
    Position pos2(14, 16);
    Rectangle r2(20, 3, pos1);
    Rectangle r3(20, 7, pos2);
    merge_horizontally(r2, r3);
    #endif

    #if TEST_NUM == 409
    Position pos1(13, 13);
    Position pos2(14, 16);
    Rectangle r2(20, 3, pos1);
    Rectangle r3(20, 7, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 410
    Position pos1(14, 13);
    Position pos2(13, 16);
    Rectangle r2(20, 3, pos1);
    Rectangle r3(20, 7, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 411
    Position pos1(14, 13);
    Position pos2(14, 15);
    Rectangle r2(20, 3, pos1);
    Rectangle r3(20, 7, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 412
    Position pos1(14, 13);
    Position pos2(14, 16);
    Rectangle r2(21, 3, pos1);
    Rectangle r3(20, 7, pos2);
    merge_vertically(r2, r3);
    #endif

    #if TEST_NUM == 501
    // jeden element
    Rectangle r{1,2};
    assert(merge_all(Rectangles{r}) == r);
    // Dwa elementy będziemy testować w 504.
    #endif

    #if TEST_NUM == 502
    // ponad dwa elementy
    bool result = merge_all(Rectangles({Rectangle{3, 20},
                                        Rectangle{7, 20, Position{3, 0}},
                                        Rectangle{10, 20, Position{0, 20}}})) == Rectangle{10, 40};
    assert(result);
    #endif

    #if TEST_NUM == 503
    // kwadrat
    bool result = merge_all(Rectangles({Rectangle{2, 2},
                                        Rectangle{2, 2, Position{2, 0}}})) == Rectangle{4, 2};
    assert(result);
    #endif

    // Kolejne 5 testów powinno zakończyć się błędem wykonania.
    #if TEST_NUM == 504
    // kontakt rogiem
    merge_all(Rectangles({
      Rectangle{2, 2},
      Rectangle{2, 2, Position{2, 2}}
    }));
    #endif

    #if TEST_NUM == 505
    // zero elementów
    Rectangles r;
    merge_all(r);
    #endif

    #if TEST_NUM == 506
    // zły indeks
    Rectangles r;
    [[maybe_unused]] auto rr = r[0];
    #endif

    #if TEST_NUM == 507
    // zły indeks
    Rectangles r{ Rectangle{2, 2} };
    [[maybe_unused]] auto rr = r[1];
    #endif

    #if TEST_NUM == 508
    // zły indeks
    Rectangles r{ Rectangle{2, 2} };
    [[maybe_unused]] auto rr = r[-1];
    #endif

    #if TEST_NUM == 610
    Position(0, 0) == Vector(0, 0);
    #endif

    #if TEST_NUM == 611
    Vector(0, 0) == Position(0, 0);
    #endif

    return 0;
}

// This macro helps checking that particular expression does not compile.
// Exactly one from EXPR1 and EXPR2 should compile.
#define CHECK_COMP_ERROR(UNIQUE_HELPER_FUN_NAME, EXPR1, EXPR2) \
template <typename Rectangle, typename Rectangles, typename Position, typename Vector> \
auto UNIQUE_HELPER_FUN_NAME([[maybe_unused]] Rectangle & rec, \
                            [[maybe_unused]] Rectangles & recs, \
                            [[maybe_unused]] Position & pos, \
                            [[maybe_unused]] Vector & vec) -> decltype(EXPR1) { \
    return EXPR1; \
} \
\
template <typename Rectangle, typename Rectangles, typename Position, typename Vector> \
auto UNIQUE_HELPER_FUN_NAME([[maybe_unused]] Rectangle & rec, \
                            [[maybe_unused]] Rectangles & recs, \
                            [[maybe_unused]] Position & pos, \
                            [[maybe_unused]] Vector & vec) -> decltype(EXPR2) { \
    return EXPR2; \
} \
\
void UNIQUE_HELPER_FUN_NAME##_test() { \
    Rectangles recs; \
    Rectangle rec(1, 2); \
    Position pos(2, 3); \
    Vector vec(2, 3); \
    UNIQUE_HELPER_FUN_NAME(rec, recs, pos, vec); \
}

#if TEST_NUM == 601
CHECK_COMP_ERROR(F1a, recs + pos, recs + vec)
#endif

#if TEST_NUM == 602
CHECK_COMP_ERROR(F1b, pos + recs, vec + recs)
#endif

#if TEST_NUM == 603
CHECK_COMP_ERROR(F1c, recs += pos, recs += vec)
#endif

#if TEST_NUM == 604
CHECK_COMP_ERROR(F2a, rec + pos, rec + vec)
#endif

#if TEST_NUM == 605
CHECK_COMP_ERROR(F2b, pos + rec, vec + rec)
#endif

#if TEST_NUM == 606
CHECK_COMP_ERROR(F2c, rec += pos, rec += vec)
#endif

#if TEST_NUM == 607
CHECK_COMP_ERROR(F3a, pos + pos, pos + vec)
#endif

#if TEST_NUM == 608
CHECK_COMP_ERROR(F3b, pos + pos, vec + pos)
#endif

#if TEST_NUM == 609
CHECK_COMP_ERROR(F3c, pos += pos, pos += vec)
#endif
