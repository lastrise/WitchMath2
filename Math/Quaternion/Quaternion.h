//
// Created by cloud on 20.11.2020.
//

#ifndef WITCH2_QUATERNION_H
#define WITCH2_QUATERNION_H

#include "../Matrix/Matrix.h"
#include "cmath"

struct Quaternion {
    double r;
    double i;
    double j;
    double k;

    Quaternion operator*(Quaternion A) const;
    Matrix toMatrix() const;
    Quaternion normalize() const;
};


#endif //WITCH2_QUATERNION_H
