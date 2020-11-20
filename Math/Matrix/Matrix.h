//
// Created by cloud on 20.11.2020.
//

#ifndef WITCH2_MATRIX_H
#define WITCH2_MATRIX_H

#include "../Vector/Vector.h"

struct Matrix {
    double values[3][3];
    Matrix& operator=(Matrix A);
    Matrix operator*(Matrix A);
    Vector operator*(Vector A);
    Matrix transpose();
};


#endif //WITCH2_MATRIX_H
