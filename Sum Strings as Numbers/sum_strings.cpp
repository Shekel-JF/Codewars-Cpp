#include <string>
using namespace std;

string sum_strings(const string& a, const string& b)
{
    string shorter = a;
    string longer = b;
    if(b.size() < a.size())
    {
        shorter = b;
        longer = a;
    }

    int longerSize = longer.size();
    int shorterSize = shorter.size();
    for(int i = shorterSize - 1; i >= 0; i--)
    {
        longer[longerSize - (shorterSize - i)] += shorter[i] - '0';
    }

    for(int i = longerSize - 1; i >= 0; i--)
    {
        while(longer[i] > '9')
        {    
            if(i == 0)
            {
                longer = "1" + longer;
                i++;
            }
            else
            {
                longer[i - 1] += 1;
            }
            longer[i] -= 10;
        }
    }
    return longer;
}