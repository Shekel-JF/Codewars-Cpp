#include <utility>
#include <vector>
#include <cmath>

using namespace std;
class SumSquaredDivisors
{
  public:
    static vector<pair<long long, long long>> listSquared(long long m, long long n)
    {      
        vector<pair<long long, long long>> result;     
        for(int i = m; i <= n; i++)
        {
            vector<int> divs;
            for(int j = 1; j <= i; j++)
            {
                if(i % j == 0)
                {
                    divs.push_back(j);
                }
            }
            int pows = 0;
            for(int d : divs)
            {
                pows += pow(d, 2);
            }
                
            if(pow(int(sqrt(pows)), 2) == pows)
            {   
                result.push_back({i, pows});
            }
        } 
        return result;
    }
};