#include <iostream>

class matrix: public vector{

private:
    int rows;
    vector* mass;

public:
    matrix();
    matrix(int rows_, int cols, int** mass_);
    matrix(matrix&& other) noexcept;
    matrix(const matrix& other);
    ~matrix();

    void print_in() override;

};