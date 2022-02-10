#include <vector>
#include <cmath>
#include "math.hpp"

using namespace std;

class Point{
public:
    Point(){
        point = {0.0, 0.0, 0.0};
    };
    Point(double x, double y, double z){
        point = {x, y, z};
    };
    Point(vector<double> vec){
        point = vec;
    };
    ~Point(){};

    void pointPrint(){
        std::cout << "X=" << point[0] << " Y=" << point[1] << " Z=" << point[2] << std::endl;
    }
    void move(const vector<double> &vec){
        point[0] += vec[0];
        point[1] += vec[1];
        point[2] += vec[2];
    }
    void scale(double s){
        point[0] *= s; point[1] *= s; point[2] *= s;
    }
    void rotate(const vector<double> &v, const double &angle){ //vec - rotation axis, angle - rotation angle
        vector<double> vec;
        vec.resize(3);
        double vecNorm = norm(v);
        vec[0] = v[0]/vecNorm; vec[1] = v[1]/vecNorm; vec[2]=v[2]/vecNorm;
        
        vector<vector<double> > rot;
        rot={
            {cos(angle)+vec[0]*vec[0]*(1-cos(angle)), vec[0]*vec[1]*(1-cos(angle))-vec[2]*sin(angle), vec[0]*vec[2]*(1-cos(angle))+vec[1]*sin(angle)},
            {vec[1]*vec[0]*(1-cos(angle))+vec[2]*sin(angle), cos(angle)+vec[1]*vec[1]*(1-cos(angle)), vec[1]*vec[2]*(1-cos(angle))-vec[0]*sin(angle)},
            {vec[2]*vec[0]*(1-cos(angle))-vec[1]*sin(angle), vec[2]*vec[1]*(1-cos(angle))+vec[0]*sin(angle), cos(angle)+vec[2]*vec[2]*(1-cos(angle))}
        };

        point = multiply(rot, point);
    }
    double dist(const vector<double> &p){ //p - point
        return sqrt(pow(p[0]-point[0],2) + pow(p[1]-point[1],2) + pow(p[2]-point[2],2));
    }
    vector<double> project(const vector<double> &plane){
        double t = -(plane[0]*point[0] + plane[1]*point[1] + plane[2]*point[2] + plane[3]) / (plane[0]*plane[0] + plane[1]*plane[1] + plane[2]*plane[2]);
        vector<double> res = {plane[0]*t+point[0], plane[1]*t+point[1], plane[2]*t+point[2]};
        return res;
    }
    vector<double> getCoords(){
        return point;
    }

    double operator[] (const int i){
        switch(i){
            case 0:
                return point[0];
            break;
            case 1:
                return point[1];
            break;
            case 2:
                return point[2];
            break;
            default:
                return NULL;
            break; 
        }
    }
    Point operator+ (const vector<double> &vec){
        point[0] += vec[0]; point[1] += vec[1]; point[2] += vec[2];
        return point;
    }

private:
    vector<double> point;
};