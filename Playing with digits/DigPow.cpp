#include <vector>
#include <cmath>
class DigPow
{
    public:
        static int digPow(int n, int p)
        {
            std::vector<int> arr;
  
            int number = n;
            while(n > 0)
            {
                arr.insert(arr.begin(), n%10);
                n/=10;
            }
      
            int result = 0;
            for(int i : arr)
            {
                result+=pow(i, p);
                p++;
            }
      
            int ret = 1;
            while(ret * number < result)
            {
                ret++;
            }
      
            if(ret * number == result)
            {
                return ret;
            }
            else
            {
                return -1;
            }
        }
};