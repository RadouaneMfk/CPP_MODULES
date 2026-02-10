#pragma once

#include "Fixed.hpp"

class Point {
    private:
        const Fixed x;
        const Fixed y;
    public:
        Point();
        Point(const float a, const float b);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();
        const Fixed& getX() const;
        const Fixed& getY() const;
};

Fixed calc_orientation(Point const p1, Point const p2, Point const point);
bool bsp( Point const a, Point const b, Point const c, Point const point);
