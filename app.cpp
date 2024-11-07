#include <iostream>
#include "vector/vector.h"
//#include "matrix/matrix.h"

using namespace std;


int main(){

    try
    {
        vector v1;
        int* mass = new int[3]{1,2,3};
        vector v2(3, mass);
        print(v1);
        print(v2);

        vector v3(3, mass);
        print(v3);

        v2.plus(v3);
        print(v2);

        v2 += v2;
        print(v2);

        v2 = v1;
        print(v1);

        const int c_elem = v3[2];
        int nc_elem = v3[2];

        cout << c_elem << " " << nc_elem << endl;
        

        delete[] mass;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
