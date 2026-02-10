#include "Point.hpp"

Fixed calc_orientation(Point const a, Point const b, Point const point)
{
    return (((b.getX() - a.getX()) * (point.getY() - a.getY())) - ((b.getY() - a.getY()) * (point.getX() - a.getX())));
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed ab = calc_orientation(a, b, point);
    Fixed bc = calc_orientation(b, c, point);
    Fixed ca = calc_orientation(c, a, point);

    if ((ab > 0 && bc > 0 && ca > 0) || (ab < 0 && bc < 0 && ca < 0))
        return true;
    return false;
}
