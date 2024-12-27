#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[], int, double[]);

int main()
{
    double A[] = {1.2, 3.5, 6.9, 7.8, 12.5, 0.5};
    int N = sizeof(A) / sizeof(A[0]);
    double B[6];
    stat(A, N, B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double inputArray[], int size, double outputArray[])
{
    double sum = 0, min = inputArray[0], max = inputArray[0], geoAcc = 1, harAcc = 0;
    for (int i = 0; i < size; i++)
    {
        sum += inputArray[i];
        geoAcc *= inputArray[i];
        harAcc += 1 / inputArray[i];
        min = inputArray[i] < min ? inputArray[i] : min;
        max = inputArray[i] > max ? inputArray[i] : max;
    }

    outputArray[0] = sum / size;
    double mean = outputArray[0];

    double acc = 0;
    for (int i = 0; i < size; i++)
    {
        acc += pow((inputArray[i] - mean), 2.0);
    }

    outputArray[1] = sqrt(acc / size);
    outputArray[2] = pow(geoAcc, 1.0 / size);
    outputArray[3] = size / harAcc;
    outputArray[4] = max;
    outputArray[5] = min;
}