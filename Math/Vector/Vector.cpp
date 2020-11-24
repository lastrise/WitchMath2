//
// Created by cloud on 20.11.2020.
//

#include "Vector.h"

Vector Vector::operator*(double h) const {
    Vector result {};
    result.x = x * h;
    result.y = y * h;
    result.z = z * h;
    return result;
}

Vector Vector::operator+(Vector other) const {
    Vector result {};
    result.x = x + other.x;
    result.y = y + other.y;
    result.z = z + other.z;
    return result;
}
