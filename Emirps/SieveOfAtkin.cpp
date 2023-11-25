#include <array>
#include <unordered_set>
#include <cmath>
#include <iostream>

int getReverse(int value)
{
    if (value % 10 == 0)
    {
        return -1;
    }
    int length = static_cast<int>(std::to_string(value).size());
    int result = 0;
    while (value > 0)
    {
        result += pow(10, length - 1) * (value % 10);
        value /= 10;
        length--;
    }
    return result;
}

std::unordered_set<int> SieveOfAtkin(int limit)
{
    std::unordered_set<int> result;
    bool sieve[limit + 1];
    for (int i = 0; i <= limit; i++)
    {
       sieve[i] = false; 
    }
        
    for (int x = 1; x * x <= limit; x++)
    {
        for (int y = 1; y * y <= limit; y++)
        {
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
            {
                sieve[n] ^= true;
            }                
 
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
            {
                sieve[n] ^= true;
            }
                
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
            {
                sieve[n] ^= true;
            }            
        }
    }

    for (int r = 5; r * r <= limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r * r; i <= limit; i += r * r)
            {
                sieve[i] = false;
            }              
        }
    }
  
    for (int a = 1; a <= limit; a++)
    {
        if (sieve[a])
        {
            result.insert(a);
        }
    }

    return result;
}


std::array<int, 3> findEmirp(const int n)
{
    int limit = pow(10, static_cast<int>(std::to_string(n - 1).size()));
    std::unordered_set<int> primes = SieveOfAtkin(limit);
    primes.erase(7);
    primes.erase(5);
    int sum = 0;
    int largest = 0;
    int extra = 0;
    for (int value : primes)
    {
        int reversed = getReverse(value);
        if (!primes.count(reversed) || value > n || value == reversed)
        {
            extra++;
            continue;
        }

        if (value > largest)
        {
            largest = value;
        }
        sum += value;
    }
    int size = primes.size() - extra;
    return {size, largest, sum};
}

