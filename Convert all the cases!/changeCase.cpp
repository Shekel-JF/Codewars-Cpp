#include <set>
#include <cctype>
#include <vector>
using namespace std;

string changeCase(const string &identifier, const string &targetCase)
{
    set<char> types;
    char targetChar = 'c';
    if(targetCase == "snake")
    {
        targetChar = '_';
    }
    else if(targetCase == "kebab")
    {
        targetChar = '-'; 
    }
    else if(targetCase != "camel")
    {
        return "";
    }
    
    for(unsigned long i = 0; i < identifier.size(); i++)
    {
        if(identifier[i] == '-' || identifier[i] == '_' || isupper(identifier[i]))
        {
            if(isupper(identifier[i]))
            {
                types.insert('A');
            }
            else
            {
                types.insert(identifier[i]);
            }       
            if(types.size() > 1)
            {
                return "";
            }         
        }
    }
  
    vector<char> tmp;
  
    for(unsigned long i = 0; i < identifier.size(); i++)
    {
        if(targetCase != "camel")
        {
            if(identifier[i] == '-' || identifier[i] == '_')
            {
                tmp.push_back(targetChar);       
            }
            else if(isupper(identifier[i]))
            {            
                tmp.push_back(targetChar);
                tmp.push_back(tolower(identifier[i]));
            }
            else
            {
                tmp.push_back(identifier[i]);
            }         
        }
        else
        {
            if(identifier[i] == '-' || identifier[i] == '_')
            {
                if(i + 1 < identifier.size())
                {
                    tmp.push_back(toupper(identifier[i + 1]));
                    i++;
                }        
            }
            else
            {
                tmp.push_back(identifier[i]);
            }       
        }
    }
    string result = "";
    for(char x : tmp)
    {
        result+=x;
    }
    return result;
}
