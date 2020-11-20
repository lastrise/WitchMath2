//
// Created by cloud on 20.11.2020.
//

#include "Matrix.h"

Matrix &Matrix::operator=(Matrix A) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            values[i][j] = A.values[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(Matrix A) {
    Matrix result{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.values[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.values[i][j] += values[i][k] * A.values[k][j];
            }
        }
    }
    return result;
}

Vector Matrix::operator*(Vector A) {
    Vector result{};
    result.x = values[0][0] * A.x + values[0][1] * A.y + values[0][2] * A.z;
    result.y = values[1][0] * A.x + values[1][1] * A.y + values[1][2] * A.z;
    result.z = values[2][0] * A.x + values[2][1] * A.y + values[2][2] * A.z;
    return result;
}

Matrix Matrix::transpose() {
    Matrix result{};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.values[i][j] = values[j][i];
        }
    }
    return result;
}
