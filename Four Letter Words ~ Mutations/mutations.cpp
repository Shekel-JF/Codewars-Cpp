#include <vector>
#include <unordered_set>
using namespace std;

int mutations(const vector<string> &alice, const vector<string> &bob, string word, int turn)
{
    unordered_set<string> used({word});
    int skipped = 0;
    
    for(unsigned long n = 0; n < bob.size() + alice.size(); n++)
    {
        string currWord = "";
        vector<string> curr = !turn ? alice : bob;
        
        for(unsigned long i = 0; i < curr.size(); i++)
        {
            if(used.count(curr[i]) == 0 && unordered_set<char>(curr[i].begin(), curr[i].end()).size() == 4)
            {
                int matchingLetters = 0;
                for(int j = 0; j < 4; j++)
                {
                    if(curr[i][j] == word[j])
                    {                           
                        matchingLetters++;
                    }
                }
                if(matchingLetters == 3)
                {
                    currWord = curr[i];
                    used.insert(currWord);
                    break;
                }
            }
        }

        if(currWord != "")
        {
            if(skipped == 1)
            {
                for(string x : used)
                {
                  cout << x << endl;
                }
                return turn;
            }
            word = currWord;
        }
        else
        {
            if(n == 0)
            {
                skipped++;
            }   
            else if(skipped == 1)
            {
                return -1;
            }
            else
            { 
                return !turn;
            }
        }
        turn = !turn;
    }
    return -1;
}