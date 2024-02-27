#include <vector>
using namespace std;
vector<int> move_zeroes(const vector<int>& input)
{
    vector<int> result;
    int zeroesCount = 0;
    for(unsigned long i = 0; i < input.size(); i++)
    {
        if(input[i] != 0)
        {
            result.push_back(input[i]);
        }
        else
        {
            zeroesCount++;
        }
    }
  
    for(int j = 0; j < zeroesCount; j++)
    {
        result.push_back(0);
    }
    return result;
}