#include <iostream>
#include "line.h"
using namespace std;

int main() {
    Line l;
    Point p;
    
    while (cin >> l.a >> l.b >> l.c >> p.x >> p.y) {
        double res = gradient(&l, &p);
        cout << CheckPointPosition(res) << std::endl;
    }
    return 0;
}