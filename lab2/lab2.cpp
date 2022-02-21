#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double h, x, y, z, i=1, dx1 = 0, dx2, gradf1 = 0, gradf = 0 , p;
    x = 0.5; y = 1; z = -2;
    p = 0.1; //погрешность
    h = 0.1; //шаг
    //f1 = pow(y, 2); f2 = pow(z, 3); f3 = (x * y) + (2 * y); f4 = z + 1;
    //f = f1 + f2 * sin(x) + f3 * f4; //общая формула
    //dx = pow(pow(z, i),3) * cos(pow(x, i)) + pow(y, i); //частная x
    //dy = 2 * pow(y, i) + pow(x, i) + 2 * pow(z, i);  //частная y
    //dz = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + 2 * pow(y, i);   //частная z
    //pow(x, i + 1) = pow(x, i) - h * dx;  //+1 k x
    do {
        dx2 = dx1;
        dx1 = pow(pow(z, i), 3) * cos(pow(x, i)) + pow(y, i);  //частная x
        gradf1 = pow(dx1, 2);
        gradf = sqrt(gradf1);
        dx2 = pow(x, i) - h * dx1;  //+ шаг
        i++;
        cout << "gradf: " << gradf;
    } while (gradf >= p);
    cout << "result: " << gradf;
}
