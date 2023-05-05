#include <string>

std::string rot13(const std::string& str)
{
    std::string res;
    char tmp;
    for(int i = 0; i < str.length(); i++)
    {
        tmp = str[i];
        if(tmp > 64 && tmp < 91)
        {
            if(tmp < 78)
            {
                tmp+=13;
            }
            else
            {
                tmp-=13;
            }
        }
        else if(tmp > 96 && tmp < 123)
        {
            if(tmp < 110)
            {
                tmp+=13;
            }
            else
            {
                tmp-=13;
            }
        }
        res+=tmp;
    }
  return res;
}
