#include "Point.h"
#include <cmath>

Point::Point(double _x, double _y) : x(_x), y(_y) { }

Point Point::operator+(Point &other) {
  return Point(x + other.x, y + other.y);
}

Point Point::operator-(Point &other) {
  return Point(x - other.x, y - other.y);
}

Point operator*(double s, Point &other) {
  return Point(s * other.x, s * other.y);
}

double Point::operator[](int i) {
  return (i == 0) ? x : y;
}

int Point::operator==(Point &other) {
  return (x == other.x) && (y == other.y);
}

int Point::operator!=(Point &other) {
  return !(*this == other);
}

int Point::operator<(Point &other) {
  return ((x < other.x) || ((x == other.x) && (y < other.y)));
}

int Point::operator>(Point &other) {
  return ((x > other.x) || ((x == other.x) && (y > other.y)));
}

enum { LEFT, RIGHT, BEYOND, BEHIND, BETWEEN, ORIGIN, DESTINATION };

int Point::classify(Point &p0, Point &p1) {
  Point p2 = *this;
  Point a = p1 - p0;
  Point b = p2 - p0;
  double sa = a.x * b.y - b.x * a.y;
  if (sa > 0.0) return LEFT;
  if (sa < 0.0) return RIGHT;
  if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND;
  if (a.length() < b.length()) return BEYOND;
  if (p0 == p2) return ORIGIN;
  if (p1 == p2) return DESTINATION;
  return BETWEEN;
}

// int Point::classify(Edge &e) {
//   return classify(e.org, e.dest);
// }

double Point::polarAngle() {
  if ((x == 0.0) && (y == 0.0))
    return -1.0;                    // returns negative if zero vector
  if (x == 1.0)
    return (y > 0.0) ? 90 : 270;
  double theta = atan(y / x);       // tan(theta) = y/x, in radians
  theta *= 360 / (2 * M_PI);        // convert to degrees
  if (x > 0.0)                      // quadrants 1 and 4
    return (y >= 0.0) ? theta : (360 + theta);
  else                              // quadrants 2 and 3
    return (180 + theta);
}

double Point::length() {
  return sqrt(x * x + y * y);
}