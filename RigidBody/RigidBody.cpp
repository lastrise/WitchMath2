//
// Created by cloud on 20.11.2020.
//

#include "RigidBody.h"

RigidBody RigidBody::f() {
    RigidBody result {};
    result.r.x = l.x * MASS;
    result.r.y = l.y * MASS;
    result.r.z = l.z * MASS;
    R = q.toMatrix();
    Vector omega = ((R * INERTIA_TENSOR) * R.transpose()) * L;
    result.q = Quaternion{0, omega.x, omega.y, omega.z} * q;
    result.q.r *= 0.5;
    result.q.i *= 0.5;
    result.q.j *= 0.5;
    result.q.k *= 0.5;
    result.l = Vector{0, 0, 0};
    result.L = Vector{0, 0, 0};
    return result;
}

RigidBody RigidBody::operator+(RigidBody A) const {
    RigidBody result {};

    result.r.x = r.x + A.r.x;
    result.r.y = r.y + A.r.y;
    result.r.z = r.z + A.r.z;

    result.q.r = q.r + A.q.r;
    result.q.i = q.i + A.q.i;
    result.q.j = q.j + A.q.j;
    result.q.k = q.k + A.q.k;

    result.l.x = l.x + A.l.x;
    result.l.y = l.y + A.l.y;
    result.l.z = l.z + A.l.z;

    result.L.x = L.x + A.L.x;
    result.L.y = L.y + A.L.y;
    result.L.z = L.z + A.L.z;

    return result;
}

RigidBody RigidBody::operator*(double h) const {
    RigidBody result {};
    result.r.x = r.x * h;
    result.r.y = r.y * h;
    result.r.z = r.z * h;

    result.q.r = q.r * h;
    result.q.i = q.i * h;
    result.q.j = q.j * h;
    result.q.k = q.k * h;

    result.l.x = l.x * h;
    result.l.y = l.y * h;
    result.l.z = l.z * h;

    result.L.x = L.x * h;
    result.L.y = L.y * h;
    result.L.z = L.z * h;
    return result;
}

RigidBody::RigidBody() {
    INERTIA_TENSOR = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    INERTIA_TENSOR.values[0][0] = (MASS / 12) * (3 * RADIUS * RADIUS + HEIGHT * HEIGHT);
    INERTIA_TENSOR.values[1][1] = (MASS / 12) * (3 * RADIUS * RADIUS + HEIGHT * HEIGHT);
    INERTIA_TENSOR.values[2][2] = MASS * RADIUS * RADIUS / 2.0;
    q = {cos(45), 1, 0, 0};
    R = q.toMatrix();
    L = Vector{2, 2, 2};
}
