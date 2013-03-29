#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

double customsetprecision(double x, int prec);

void normalize(double Matrix[][100], int n)
{
    double sum;
    for(int j = 0; j < n; j++)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += Matrix[i][j];
        for(int i = 0; i < n; i++)
        {
            Matrix[i][j] /= sum;
            if(Matrix[i][j] <= 0.01)
                Matrix[i][j] = 0;
            else if(Matrix[i][j] >= 0.99)
                Matrix[i][j] = 1;
        }
    }
}

void multiply(double Matrix[100][100], int n)
{
    double sum = 0;
    double res[100][100];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            sum = 0;
            for(int k = 0; k < n; k++)
                sum += Matrix[i][k]*Matrix[k][j];
            res[i][j] = sum;
        }
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            Matrix[i][j] = res[i][j];
}

void inflate(double Matrix[][100], int n, int p)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            Matrix[i][j] = pow(Matrix[i][j], p);
}

void roundmatrixto(double Matrix[][100], int n, int prec)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            Matrix[i][j] = customsetprecision(Matrix[i][j], prec);
}
