#include <vector>
#include <utility>
#include <queue>
using namespace std;
pair<int, int> longest_mountain_pass(const vector<int>& mountains, int energy)
{
    unsigned long mountainsLength = mountains.size();
    if(mountainsLength <= 1)
    {
        return {mountainsLength, 0};
    }

    int length = 1;
    int currLength = 1;
    int index = 0;  
    int currIndex = 0;
    
    queue<int> trip;
    for(unsigned long j = 0; j < mountainsLength - 1; j++)
    {
        int effort = mountains[j + 1] - mountains[j];
        if(energy - effort < 0)
        {
            while(!trip.empty())
            {
                int tmp = trip.front();
                trip.pop();
                energy+=tmp;
                currLength--;
                currIndex++;
              
                if(energy - effort >= 0)
                {
                    break;
                }
            }
            if(energy - effort < 0)
            {
                currIndex++;
                continue;
            }
        }
        effort = max(0, effort);
        trip.push(effort);
        energy-=effort;

        currLength++;   
        if(currLength > length)
        {
            length = currLength;
            index = currIndex;
        }
    }
    return {length, index};
}