#include <iostream>

using namespace std;

class vector{

public:
    vector();
    vector(int size_, int*mass=nullptr);
    ~vector() noexcept;
    vector(vector&& other) noexcept; //replace
    vector(const vector& other); //copy
    friend void print(const vector& v);
    vector& plus(vector& other);
    vector& operator+=(const vector& other);
    vector& operator=(vector&& other) noexcept;
    vector& operator=(const vector& other);
    int operator[](const int index) const;
    int operator[](const int index);
    int getSize() const;
private:
    int size;
    int*vec;
};