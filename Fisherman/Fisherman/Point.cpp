#include "Point.h"

Point::Point()
{
}

Point::Point(int x, int y)
	: x(x),
	  y(y)
{
}

Point::~Point()
{
}

int Point::getX()
{
	return x;
}

void Point::setX(int x)
{
	x = x;
}

int Point::getY()
{
	return y;
}

void Point::setY(int y)
{
	y = y;
}
