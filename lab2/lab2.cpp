#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int h, f, f1, f2, f3, f4, x, y, z, i, dx, dy, dz;
    f1 = pow(y, 2); f2 = pow(z, 3); f3 = (x * y) + (2 * y); f4 = z + 1;
    f = f1 + f2 * sin(x) + f3 * f4; //общая формула
    dx = pow(pow(z, i),3) * cos(pow(x, i)) + pow(y, i); //частная x
    dy = 2 * pow(y, i) + pow(x, i) + 2 * pow(z, i);  //частная y
    dz = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + 2 * pow(y, i);   //частная z
    pow(x, i + 1) = pow(x, i) - h * dx;
}
