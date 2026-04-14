#include "line.h"
#include <string>
using namespace std;

double gradient(const Line * l, const Point * p) {
    return (l->a * p->x) + (l->b * p->y) + l->c;
}

string CheckPointPosition(double val) {
    if (val > EPSILON) {
        return "Left";
    } else if (val < -EPSILON) {
        return "Right";
    } else {
        return "On Line";
    }
}