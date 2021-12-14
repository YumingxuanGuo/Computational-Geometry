#pragma once

class Point {
  public:
    double x;
    double y;

    Point(double _x = 0.0, double _y = 0.0);
    Point operator+(Point &other);
    Point operator-(Point &other);
    friend Point operator*(double s, Point &other);
    double operator[](int coor);
    int operator==(Point &other);
    int operator!=(Point &other);
    int operator<(Point &other);
    int operator>(Point &other);

    int classify(Point &p0, Point &p1);
    // int classify(Edge &e);
    double polarAngle();
    double length();
    // double distance(Edge &e);
};