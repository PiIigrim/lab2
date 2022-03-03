#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    char MaxOrMin;
    double h, x = 2, y = -1, z = 4, f, i = 1, dx1 = 0, dx2, gradfx = 0, gradfy = 0, gradfz = 0, gradf, p, dy1 = 0, dy2, dz1 = 0, dz2, minl, maxr;
    p = 0.1;
    h = 0.5; //шаг
    cout << "Ищем минимум или максимум?(1-мин; 2-макс)" << endl;
    cin >> MaxOrMin;
    cout << "Введите левую границу: ";
    cin >> minl;
    cout << "Введите правую границу: ";
    cin >> maxr;
    cout << "x=" << x << " " << "y=" << y << " " << "z=" << z << endl;
    //f1 = pow(y, 2); f2 = pow(z, 3); f3 = (x * y) + (2 * y); f4 = z + 1;
    switch (MaxOrMin) {
    case '1':
        //минимум
        do {
            //проверка границы
            if (gradfx <= minl) {
                gradfx = minl;
            }
            else {
                dx1 = pow(pow(z, i), 3) * cos(pow(x, i)) + (pow(y, i) * pow(z, i)) + pow(y, i);
                gradfx = sqrt(pow(dx1, 2));
            }
            if (gradfy <= minl) {
                gradfy = minl;
            }
            else {
                dy1 = 2 * pow(y, i) + (pow(x, i) * pow(z, i)) + pow(x, i) + 2 * pow(z, i) + pow(z, i);
                gradfy = sqrt(pow(dy1, 2));
            }
            if (gradfz <= minl) {
                gradfz = minl;
            }
            else {
                dz1 = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + (pow(x, i) * pow(y, i)) + 2 * pow(y, i);
                gradfz = sqrt(pow(dz1, 2));
            }
            //расчет шага
            dx2 = pow(x, i) - h * dx1; dy2 = pow(y, i) - h * dy1; dz2 = pow(z, i) - h * dz1;
            dx2 = dx1; dy2 = dy1; dz2 = dz1;
            i++;
            //расчет финального значения
            gradf = pow(gradfy, 2) + pow(gradfz, 3) * sin(gradfx) + (gradfx * gradfy) + (2 * gradfy) * (gradfz + 1);
        } while (gradf > p);
        break;
    case '2':
        //максимум
        do {
            //проверка границы
            if (gradfx >= maxr) {
                gradfx = maxr;
            }
            else {
                dx1 = pow(pow(z, i), 3) * cos(pow(x, i)) + (pow(y, i) * pow(z, i)) + pow(y, i);
                gradfx = sqrt(pow(dx1, 2));
            }
            if (gradfy >= maxr) {
                gradfy = maxr;
            }
            else {
                dy1 = 2 * pow(y, i) + (pow(x, i) * pow(z, i)) + pow(x, i) + 2 * pow(z, i) + pow(z, i);
                gradfy = sqrt(pow(dy1, 2));
            }
            if (gradfz >= maxr) {
                gradfz = maxr;
            }
            else {
                dz1 = 3 * pow(pow(z, i), 2) * sin(pow(x, i)) + (pow(x, i) * pow(y, i)) + 2 * pow(y, i);
                gradfz = sqrt(pow(dz1, 2));
            }
            //расчет шага
            dx2 = pow(x, i) - h * dx1; dy2 = pow(y, i) - h * dy1; dz2 = pow(z, i) - h * dz1;
            dx2 = dx1; dy2 = dy1; dz2 = dz1;
            i++;
            //расчет финального значения
            gradf = pow(gradfy, 2) + pow(gradfz, 3) * sin(gradfx) + (gradfx * gradfy) + (2 * gradfy) * (gradfz + 1);
        } while (gradf < p);
        break;
    }
    cout << "gradfx: " << gradfx << " " << "gradfy: " << gradfy << " " << "gradfz: " << gradfz << endl;
    cout << "final coordinate(x,y,z): (" << fixed << setprecision(15) << gradfx << ", " << gradfy << ", " << gradfz << ")" << endl;
    cout << "final result: " << gradf << endl;
}