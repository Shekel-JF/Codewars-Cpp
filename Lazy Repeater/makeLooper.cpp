#include <string>

auto makeLooper(const std::string& str) 
{
    return [str, index = 0] () mutable -> char
    {
        char result = str[index % str.size()];
        index++;
        return result;
    };
}