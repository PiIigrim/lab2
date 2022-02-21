#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double h, x, y, z, f, i=1, dx1 = 0, dx2, gradfx = 0 , gradfy = 0, gradfz = 0, p, dy1 = 0, dy2, dz1 = 0, dz2;
    x = -0.5; y = 0.2; z = 0.1;
    p = 0.01;
    h = 0.1; //шаг
    //f1 = pow(y, 2); f2 = pow(z, 3); f3 = (x * y) + (2 * y); f4 = z + 1;
    do {
        dx2 = dx1;
        dx1 = pow(pow(z, i), 3) * cos(pow(x, i)) + pow(y, i);
        gradfx = sqrt(pow(dx1, 2));
        dx2 = pow(x, i) - h * dx1;  
        i++;
    } while (gradfx >= p);
    i-=2;
    dx1 = pow(pow(z, i), 3) * cos(pow(x, i)) + pow(y, i);
    gradfx = sqrt(pow(dx1, 2));
    cout << "result x: " << gradfx << endl;
    
    do {
        dy2 = dy1;
        dy1 = 2 * pow(y, i) + pow(x, i) + 2 * pow(z, i);
        gradfy = sqrt(pow(dy1, 2));
        dy2 = pow(y, i) - h * dy1;  
        i++;
    } while (gradfy >= p);
    i -= 2;
    dy1 = 2 * pow(y, i) + pow(x, i) + 2 * pow(z, i);
    gradfy = sqrt(pow(dy1, 2));
    cout << "result y: " << gradfy << endl;

    do {
        dz2 = dz1;
        dz1 = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + 2 * pow(y, i);
        gradfz = sqrt(pow(dz1, 2));
        dz2 = pow(z, i) - h * dz1;  
        i++;
    } while (gradfz >= p);
    i -= 2;
    dz1 = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + 2 * pow(y, i);
    gradfz = sqrt(pow(dz1, 2));
    cout << "result z: " << gradfz << endl;

    cout << "final coordinate: (" << gradfx << ", " << gradfy << ", " << gradfz << ")" << endl;
    f = pow(gradfy, 2) + pow(gradfz, 3) * sin(gradfx) + (gradfx * gradfy) + (2 * gradfy) * (gradfz + 1);
    cout << "final result: " << f << endl;
}
