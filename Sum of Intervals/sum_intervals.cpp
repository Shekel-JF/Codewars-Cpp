#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int sum_intervals(vector<pair<int, int>> intervals)
{
    int result = 0;
    sort(intervals.begin(), intervals.end());
  
    int currFirst = intervals[0].first;
    int currSecond = intervals[0].second;
  
    for(unsigned long i = 1; i < intervals.size(); i++)
    {
        if(intervals[i].first <= currSecond)
        {
            currSecond = max(currSecond, intervals[i].second);
        }
        else
        {
            result+= currSecond - currFirst;
            currFirst = intervals[i].first;
            currSecond = intervals[i].second;
        }
    }
    result+= currSecond - currFirst;
    
    return result;
}