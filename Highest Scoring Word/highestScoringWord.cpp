#include <string>
#include <map>
std::string highestScoringWord(const std::string &str)
{
    std::map<char, int> weights;
    char c = 'a';
    for (int i = 1; i <= 26; i++)
    {
        weights[c] = i;
        c++;
    }
    std::string result = "";
    int high = 0;
    int tmp = 0;
    int length = 0;
    for(int i = 0; i <= str.length(); i++)
    {
        if(str[i] != ' ' && i < str.length())
        {
            tmp+=weights[str[i]];
            length++;
        }
        else
        {
            if(tmp > high)
            {
                high = tmp;
                result = str.substr(i - length, length);
            }
            tmp = 0;
            length = 0;
        }
        
    }
    return result;
}