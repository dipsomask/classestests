#include <iostream>
#include "vector.h"

using namespace std;

vector::vector(){
    size = 0;
    vec = nullptr;
}

vector::vector(int size_, int* mass){
    if(size_ < 1){
        throw length_error("size can't be smaller than 1 in constructor 'vector(int size_, int* mass)'");
    }
    size = size_;
    vec = new int[size];
    for(int i = 0; i < size; i++){
        vec[i] = 0;
        if(mass!=nullptr)
            vec[i] = mass[i];
    }
}

vector::~vector() noexcept{
    if(vec != nullptr)
        delete[] vec;
    size = 0;
    vec = nullptr;
}

vector::vector(vector&& other) noexcept{
    std::swap(other.size, size);
    std::swap(other.vec, vec);
}

vector::vector(const vector& other){
    size = other.size;
    if(size >= 1){
        vec = new int[size];
        for(int i = 0; i < size; i++){
            vec[i] = other.vec[i];
        }
    }
    else{
        vec = nullptr;
    }
}

void print(const vector& v){
    if(v.size == 0){
        cout << "null" << endl;
        return;
    }
    for(int i = 0; i < v.size; i++){
        cout << v.vec[i] << " ";
    }
    cout << endl;
}

void vector::print_in(){
    if(size == 0){
        cout << "null" << endl;
        return;
    }
    for(int i = 0; i < size; i++){
        cout << vec[i] << " ";
    }
    cout << endl;
}

vector& vector::plus(vector& other){
    if(other.vec == nullptr || other.size != size){
        throw range_error("using null ptr or differnt sizes");
    }
    for(int i = 0; i < size; i++){
        vec[i] += other.vec[i];
    }
    return *this;
}

vector& vector::operator+=(const vector& other){
    if(other.vec == nullptr || other.size != size){
        throw range_error("using null ptr or differnt sizes");
    }
    for(int i = 0; i < size; i++){
        vec[i] += other.vec[i];
    }
    return *this;
}

vector& vector::operator=(vector&& other) noexcept{
    std::swap(size, other.size);
    std::swap(vec, other.vec);
    return *this;    
}

vector& vector::operator=(const vector& other){
    if(vec != nullptr){
        delete[] vec;
    }
    size = other.size;
    if(other.vec != nullptr){
        vec = new int[size];
        for(int i = 0; i < size; i++){
            vec[i] = other.vec[i];
        }
        return *this;
    }
    vec = nullptr;
    return *this;
}

int vector::operator[](const int index) const{
    if(index < 0){
        throw underflow_error("index " + to_string(index) + " under the flow");
    }
    else if(index >= size){
        throw overflow_error("index " + to_string(index) + " over the flow");
    }
    return vec[index];
}

int vector::operator[](const int index){
    if(index < 0){
        throw underflow_error("index " + to_string(index) + " under the flow");
    }
    else if(index >= size){
        throw overflow_error("index " + to_string(index) + " over the flow");
    }
    return vec[index];
}

int vector::getSize() const{
    return size;
}