#include <string>
#include <sstream>

std::string add(const std::string& a, const std::string& b)
{
    int size = std::max(a.length(), b.length());
    int carry = 0;
    std::ostringstream result;

    for(int i = 1; i <= size; i++)
    {
        int sum = carry;
        if(i <= a.length())
        {
            sum += a[a.length() - i] - '0';
        }
        if(i <= b.length())
        {
            sum += b[b.length() - i] - '0';
        }
        carry = sum / 10;
        result << (sum % 10);
    }

    if(carry != 0)
    {
        result << carry;
    }

    std::string out = result.str();
    std::reverse(out.begin(), out.end());
    return out;
}
