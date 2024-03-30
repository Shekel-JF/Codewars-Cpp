#include <cmath>
long zeros(long n)
{
    int k = log(n)/log(5);
    long result = 0;
    for(int i = 1; i <= k; i++)
    {
       result+= n/pow(5, i);
    }
    return result;
}