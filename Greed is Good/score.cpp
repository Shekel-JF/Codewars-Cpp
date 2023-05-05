#include <vector>

int score(const std::vector<int>& dice)
{
    int score = 0;
    std::map<int, int> counters;
    for(int i: dice)
    {
        counters[i]++;
    }
    for(int i = 1; i < 7; i++)
    {
        if(counters[i] > 2)
        {
            int multiply = 100;
            if(i==1)
            {
                multiply*=10;
            }
            score+=multiply*i;
            counters[i] -= 3;
            break;
        }
    }
    while(counters[1] > 0)
    {
        score+=100;
        counters[1]--;
    }
    while(counters[5] > 0)
    {
        score+=50;
        counters[5]--;
    }
    return score;
}
