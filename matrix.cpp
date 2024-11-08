#include <iostream>
#include "vector.h"
#include "matrix.h"

using namespace std;

matrix::matrix(): vector(){
    rows = 0;
    mass = nullptr;
}

matrix::matrix(int rows_, int cols, int** mass_){
    rows = rows_;
    mass = new vector[rows];
    for(int i = 0; i<rows; i++){
        mass[i] = vector(cols, mass_[i]);
    }
}

matrix::matrix(matrix&& other) noexcept{
    swap(rows, other.rows);
    swap(mass, other.mass);
}

matrix::matrix(const matrix& other){
    rows = other.rows;
    mass = new vector[rows];
    for(int i = 0; i<rows; i++){
        mass[i] = other.mass[i];
    }
}

matrix::~matrix(){
    rows = 0;
    delete[] mass;
    mass = nullptr;
}

void matrix::print_in(){
    if(rows == 0){
        cout << "null" << endl;
        return;
    }
    for(int i = 0; i<rows; i++){
        mass[i].print_in();
    }
}