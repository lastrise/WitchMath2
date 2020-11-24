//
// Created by cloud on 20.11.2020.
//

#ifndef WITCH2_RIGIDBODY_H
#define WITCH2_RIGIDBODY_H

#include "../Math/Matrix/Matrix.h"
#include "../Math/Quaternion/Quaternion.h"
#include "../Math/Vector/Vector.h"


const double HEIGHT = 2, RADIUS = 1;
const double MASS = 0.02;

struct RigidBody {
    Matrix R {};
    Vector r {}, l {}, L {};
    Quaternion q {};
    Matrix INERTIA_TENSOR {};

    RigidBody();
    RigidBody f();
    RigidBody operator+(RigidBody A) const;
    RigidBody operator*(double h) const;
};


#endif //WITCH2_RIGIDBODY_H
