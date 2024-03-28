#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> divide_strings(string a, string b) 
{
    vector<string> quot_rema = {"0", "0"};
    if(a.length() < b.length())
    {
        return {"0", a};
    }

    for(unsigned long i = 1; i <= a.length() - b.length(); i++)
    {
        int subs = 0;
        while(a.substr(i, b.size()) >= b || a[i-1] != '0')
        {
            for(int k = b.length() - 1; k >= 0; k--)
            {
                if(a[i+k] < b[k])
                {
                    a[i+k-1]--;
                    a[i+k] += 10;
                }
                a[i+k] = 48 + int(a[i+k]) - int(b[k]);
            }
            subs++;
        }
        quot_rema[0] = quot_rema[0] + to_string(subs);
    }
    quot_rema[1] = a; 
    for(unsigned long i = 0; i < quot_rema.size(); i++)
    {
        unsigned long j = 0;
        while(quot_rema[i][j] == '0' and j != quot_rema[i].length() - 1)
        {
            j++;
        }
        quot_rema[i].erase(0,j);
    }
    return quot_rema;
}