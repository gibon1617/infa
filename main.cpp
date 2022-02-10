#include <iostream>
#include "figure.hpp"
#include <vector>

using namespace std;

const double PI = 3.141592;

void main(){
/*
    vector<double> plane = {-1, 2, -1, 2};
    vector<double> projection;
    vector<double> x = {1,2,3};
    Point p(2, 1, -3);

    p.pointPrint();

    projection = p.project(plane);

    Point p1(projection);
    p1.pointPrint();

    vector<double> xAxis = {1, 1, 0};
    vector<double> yAxis = {0, 1, 0};
    vector<double> zAxis = {0, 0, 1};
    double angle = 90.*PI/180.;
    Point yPoint = {0, 1, 0};

    yPoint.rotate(xAxis, angle);
    yPoint.pointPrint();
    yPoint.rotate(yAxis, angle);
    yPoint.pointPrint();
    yPoint.rotate(zAxis, angle);
    yPoint.pointPrint();

    Point zPoint = {0, 0, 1};
    vector<double> a = {1,0,0};
    cout << zPoint.dist(a) << endl;
    cout << zPoint[2] << endl;*/

    //vector<vector<double> > figura = {{1,2,3},{4,5,6},{7,8,9}};
    Point p1(1,2,3), p2(4,5,6), p3(7,8,9), p4(10,11,12);
    Figure a(p1);
    a.printPoints();
    a.pushPoint(p2);
    a.printPoints();
    a.pushPoint(p3);
    a.printPoints();
    a.deletePoint(1);
    a.printPoints();
    vector<double> v1 = {0.5, 0.5, 0.5};
    a.move(v1);
    a.printPoints();
    a.rotate({1,0,0}, 90*PI/180.);
    a.printPoints();

    vector<vector<double> > vec ={{1,1,1},{1,1,1},{7,8,9}};
    Figure b(vec);
    b.printPoints();
    b.pushPoint(p2);
    b.printPoints();
    b.pushPoint(p3);
    b.printPoints();
    b.deletePoint(1);
    b.printPoints();
    //vector<double> v2 = {0.5, 0.5, 0.5};
    b.move(v1);
    b.printPoints();
    b.rotate({1,1,0}, 90*PI/180.);
    b.printPoints();

    vector<double> plane = {1, 0, 0, 0};
    b.project(plane);
    b.printPoints();
    
    vector<Point> vec2= {p1, p2, p3, p4};
    Figure c(vec2);
    c.printPoints();
    c.pushPoint(p2);
    c.printPoints();
    c.pushPoint(p3);
    c.printPoints();
    c.deletePoint(1);
    c.printPoints();
    //vector<double> v2 = {0.5, 0.5, 0.5};
    c.move(v1);
    c.printPoints();
    c.rotate({1,1,0}, 90*PI/180.);
    c.printPoints();
}