#include <cmath>

int sum_of_squares(int n)
{
    double sqrt_tmp = sqrt(n);
    if(sqrt_tmp == int(sqrt_tmp))
    {
        return 1;
    }
  
    for(int i = 1; i < sqrt_tmp; i++)
    {
        sqrt_tmp = sqrt(n - i * i);
        if(sqrt_tmp == int(sqrt_tmp))
        {
            return 2;
        }
    }
  
    while(n % 4 == 0)
    {
        n/=4;
    }
    if(n % 8 == 7)
    {
        return 4;
    }
  
    return 3;
}