#include <vector>

int maxSequence(const std::vector<int>& arr)
{
    int max = 0;
    int tmp = 0;

      
    for(int i = 0; i < arr.size(); i++)
    {
        tmp+=arr[i];
        if(tmp > max)
        {
            max = tmp;
        }    
        if(tmp < 0)
        {
            tmp = 0;
        }
    }
    return max;
}
