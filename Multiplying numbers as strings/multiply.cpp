#include <iostream>
#include <string>
#include <vector>

using namespace std;

string removeZero(string str) 
{ 
    int i = 0; 
    while (str[i] == '0')
    {
        i++; 
    }
    str.erase(0, i); 
  
    return str; 
} 

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

string multiply(string a, string b)
{
    if(a == "0" || b == "0")
    {
        return "0";
    }
    a = removeZero(a);
    b = removeZero(b);

    string result = "0";
    int sizeA = a.size();
    int sizeB = b.size();
    vector<string> mul;
    for(int i = 0; i < sizeA + sizeB; i++)
    {
        mul.push_back("0");
    }
  
    for(int i = 0; i < sizeA; i++)
    {
        for(int j = 0; j < sizeB; j++)
        {     
            mul[i + j] = sum_strings(mul[i + j], to_string((a[sizeA - i - 1] - '0') * (b[sizeB - j - 1] - '0')));     
        }
    }
  
    for(unsigned long i = 0; i < mul.size() - 1; i++)
    {
        for(unsigned long j = 0; j < i; j++)
        {
            mul[i] += "0";
        }
    }
  
    for(string s : mul)
    {
        result = sum_strings(result, s);
    }
    return result;
}