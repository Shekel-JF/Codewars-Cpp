#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void permuting(string remainingLetters, string curr, unsigned long size, vector<string> &result)
{
    int rlSize = remainingLetters.size();
    for(int i = 0; i < rlSize; i++)
    {
        string rl = remainingLetters;
        char letter = rl[i];
        rl.erase(rl.begin() + i);
        permuting(rl, curr + letter, size,  result);
    }
    if(curr.size() == size && !(find(result.begin(), result.end(), curr) != result.end()))
    {
        result.push_back(curr);
    }
}

vector<string> permutations(string s)
{
    unsigned long size = s.size();
    vector<string> result; 
    permuting(s, "", size, result);
  
    return result;
}