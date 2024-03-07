#include <string>

using namespace std;

bool is_merge(const std::string& s, const std::string& part1, const std::string& part2)
{
    if(s == "")
    {
        return part1 == "" && part2 == "";
    }
  
    bool merging1 = false;
    bool merging2 = false;
  
    if(part1.size() > 0 && part1[0] == s[0])
    {
        merging1 = is_merge(s.substr(1), part1.substr(1), part2);
    }
    if(part2.size() > 0 && part2[0] == s[0])
    {
        merging2 = is_merge(s.substr(1), part1, part2.substr(1));
    }
    return merging1 || merging2;
}