#include<iostream>
#include<iomanip>
using namespace std;

class Point{
    public:
    double x, y;
    void import(){
        cin >> x >> y;
    }
};

class Line{
    public:
    double a, b;
    Line(Point P1, Point P2){
        a = (P1.y - P2.y) / (P1.x - P2.x);
        b = (P1.y - P1.x * a);
    }
};

void findIntersectionPoint(Line d1, Line d2){
    if(d1.a == d2.a && d1.b == d2.b){
        cout << "MANY";
    }else if(d1.a == d2.a && d1.b != d2.b){
        cout << "NO";
    }else{
        double x, y;
        x = (d2.b - d1.b) / (d1.a - d2.a);
        y = d1.a * x + d1.b;
        cout << setprecision(2) << fixed << x << " " << y;
    }
}

int main(){

    Point A, B, C, D;
    A.import();
    B.import();
    C.import();
    D.import();
    Line AB(A, B);
    Line CD(C, D);
    findIntersectionPoint(AB, CD);

    return 0;
}
