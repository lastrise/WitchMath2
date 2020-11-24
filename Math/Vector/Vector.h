//
// Created by cloud on 20.11.2020.
//

#ifndef WITCH2_VECTOR_H
#define WITCH2_VECTOR_H


struct Vector {
    double x;
    double y;
    double z;

    Vector operator*(double h) const;
    Vector operator+(Vector other) const;
};


#endif //WITCH2_VECTOR_H
