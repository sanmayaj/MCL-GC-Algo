#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

double customsetprecision(double x, int prec)
{
    return ceil( x * pow(10,(double)prec) - .4999999999999)
            / pow(10,(double)prec);
}

/*double customsetprecision2(double x, int prec)
{
    return ceil( x * pow(10,(double)prec) + .5)
            / pow(10,(double)prec);
}

double customsetprecision3(double x, int prec)
{
    x *= pow(10, (double)prec);
    return (double)((long)((2*x + .5)/2))/pow(10, (double)prec);
}*/
