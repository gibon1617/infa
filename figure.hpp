#include "point.hpp"

using namespace std;

class Figure{
public:
    Figure(const vector<vector<double> > &points){
        vector<double> temp;
        Point *p = new Point[points.size()];
        int i=0;
        for(auto it = points.begin(); it != points.end(); it++){
            temp = *it;
            p[i] = Point(temp);
            fig.push_back(p[i]);
            i++;
        }
    }
    Figure(const vector<Point> &points){
        fig = points;
    }
    Figure(const Point &points){
        fig.push_back(points);
    }
    ~Figure(){
       // delete []p;
    }

    void pushPoint(vector<double> &point){
        fig.push_back(point);
    }
    void pushPoint(Point &point){
        fig.push_back(point.getCoords());
    }
    void printPoints(){
        vector<double> temp;
        int i=0;
        for(auto it = fig.begin(); it != fig.end(); it++){
            i++;
            temp = it->getCoords();
            cout << "Point " << i << ":\tX: " << temp[0] << "\tY: " << temp[1] << "\tZ: " << temp[2] << endl;
        }
    }
    void deletePoint(const int i){
        if(i >= 1){
            fig.erase(fig.begin() + i - 1);
        }
    }
    void rotate(const vector<double> &vec, const double &angle){
        for(auto it = fig.begin(); it != fig.end(); it++){
            it->rotate(vec, angle);
        }
    }
    void move(const vector<double> &vec){
        for(auto it = fig.begin(); it != fig.end(); it++){
            it->move(vec);
        }
    }
    void project(const vector<double> &plane){
        int i=0;
        for(auto it = fig.begin(); it != fig.end(); it++){
            fig[i] = it->project(plane);
            i++;
        }  
    }
private:
    vector<Point> fig;
    Figure(){};
};